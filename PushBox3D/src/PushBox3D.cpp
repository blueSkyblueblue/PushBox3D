#include <EntryPoint.h>
#include <BoxEngine.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Layer
{
public:
	ExampleLayer()
	{
	}

	virtual ~ExampleLayer() override 
	{
	}
	
	virtual void onAttach() override 
	{
		Window& window = Application::get()->getWindow();
		window.setVSync(true);

		float vertices[] = {
			-0.5f, -0.3f,	0.234f, 0.234f, 0.453f,
			 0.5f, -0.3f,	0.433f, 0.898f, 0.854f,
			 0.0f,  0.5f,	0.834f, 0.234f, 0.473f,
		};

		uint32_t indices[3] = { 0, 1, 2 };

		m_VAO.bind();
		m_VBO.loadVertices(vertices, sizeof(vertices));
		m_IBO.loadIndices(indices, sizeof(indices));

		VertexAttribLayout layout;
		layout.push(VertexElement::FLOAT2);
		layout.push(VertexElement::FLOAT3);
		m_VBO.loadLayout(layout);

		const std::string vertexShader = R"(
			#version 460 core		

			layout(location = 0) in vec4 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec4 v_Color;

			void main()
			{
				v_Color = a_Color;
				gl_Position = a_Position;
			}
		)";

		const std::string fragmentShader = R"(
			#version 460 core
		
			in vec4 v_Color;

			void main()
			{
				gl_FragColor = v_Color;
			}
		)";

		m_Shader.loadFromSource(vertexShader, fragmentShader);

		auto [width, height] = Application::get()->getWindowSize();
		Renderer2D::initialize(0.f, (float)width, 0.f, (float)height);
	}
	
	virtual void onDetach() override {}
	virtual void onUpdate(Timestep ts) override
	{
		printf("Seconds Per Frame: %f\n", (float)ts);
		printf("FPS: %f\n", 1.0f / (float)ts);
		static float time = 0.f;
		time += ts;

		RendererCommand::setClearColor(m_BackgroundColor.r, m_BackgroundColor.g, m_BackgroundColor.b, m_BackgroundColor.a);
		RendererCommand::clear();

		m_VAO.bind();
		m_Shader.use();
		Renderer::drawElements(3);

		auto [width, height] = Application::get()->getWindowSize();

		static float speed = 400.f;
		m_TranslationLengthHorizontally += ts * speed;

		if (m_TranslationLengthHorizontally >= width - 500)
			speed = -400.f;
		else if (m_TranslationLengthHorizontally <= 0)	
			speed = 400.f;

		m_BoxRotationMat = glm::translate(glm::mat4(1.f), { 700.f, 700.f, 0.f})
			* glm::rotate(glm::identity<glm::mat4>(), time * 4, { 0.f, 0.f, 1.f })
			* glm::scale(glm::mat4(1.f), { 100.f, 100.f, 1.f });

		Renderer2D::rectangle(m_TranslationLengthHorizontally, 100, 500, 500, glm::vec3(0.343f, 0.434f, 0.345f));
		Renderer2D::rectangle(m_BoxRotationMat, glm::vec3(0.f, 0.6f, 0.6f));
	}

	virtual void onEvent(Event& e) override
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowResizeEvent>(
			[](WindowResizeEvent& e) -> bool
			{
				Renderer::setViewport(0, 0, e.Width, e.Height);
				Renderer2D::resize(0.f, (float)e.Width, 0.f, (float)e.Height);
				return false;
			});

		dispatcher.dispatch<KeyPressEvent>(
			[](KeyPressEvent& e) -> bool
			{
				if (e.Key == BOXENGINE_KEY_ESCAPE && e.IsRepeated == false)
					Application::get()->close();

				return false;
			});
	}

private:
	VertexArray m_VAO;
	VertexBuffer m_VBO;
	IndexBuffer m_IBO;
	Shader m_Shader;

	float m_TranslationLengthHorizontally = 0.f;
	
	glm::mat4 m_BoxRotationMat = { 0.f };

	glm::vec4 m_BackgroundColor = { 0.5f, 0.5f, 0.0f, 1.0f };
};

class PushBox3D : public Application
{
public:
	PushBox3D()
		: m_TestLayer {}
	{
		pushLayer(&m_TestLayer);
	}

	~PushBox3D()
	{
	}

private:
	ExampleLayer m_TestLayer;
};

Application* Application::s_Instance = new PushBox3D;
