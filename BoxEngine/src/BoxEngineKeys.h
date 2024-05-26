#pragma once

#define BOXENGINE_KEY_UNKNOWN            -1

#define BOXENGINE_KEY_SPACE              32
#define BOXENGINE_KEY_APOSTROPHE         39  
#define BOXENGINE_KEY_COMMA              44  
#define BOXENGINE_KEY_MINUS              45  
#define BOXENGINE_KEY_PERIOD             46  
#define BOXENGINE_KEY_SLASH              47  
#define BOXENGINE_KEY_0                  48
#define BOXENGINE_KEY_1                  49
#define BOXENGINE_KEY_2                  50
#define BOXENGINE_KEY_3                  51
#define BOXENGINE_KEY_4                  52
#define BOXENGINE_KEY_5                  53
#define BOXENGINE_KEY_6                  54
#define BOXENGINE_KEY_7                  55
#define BOXENGINE_KEY_8                  56
#define BOXENGINE_KEY_9                  57
#define BOXENGINE_KEY_SEMICOLON          59  
#define BOXENGINE_KEY_EQUAL              61  
#define BOXENGINE_KEY_A                  65
#define BOXENGINE_KEY_B                  66
#define BOXENGINE_KEY_C                  67
#define BOXENGINE_KEY_D                  68
#define BOXENGINE_KEY_E                  69
#define BOXENGINE_KEY_F                  70
#define BOXENGINE_KEY_G                  71
#define BOXENGINE_KEY_H                  72
#define BOXENGINE_KEY_I                  73
#define BOXENGINE_KEY_J                  74
#define BOXENGINE_KEY_K                  75
#define BOXENGINE_KEY_L                  76
#define BOXENGINE_KEY_M                  77
#define BOXENGINE_KEY_N                  78
#define BOXENGINE_KEY_O                  79
#define BOXENGINE_KEY_P                  80
#define BOXENGINE_KEY_Q                  81
#define BOXENGINE_KEY_R                  82
#define BOXENGINE_KEY_S                  83
#define BOXENGINE_KEY_T                  84
#define BOXENGINE_KEY_U                  85
#define BOXENGINE_KEY_V                  86
#define BOXENGINE_KEY_W                  87
#define BOXENGINE_KEY_X                  88
#define BOXENGINE_KEY_Y                  89
#define BOXENGINE_KEY_Z                  90
#define BOXENGINE_KEY_LEFT_BRACKET       91 
#define BOXENGINE_KEY_BACKSLASH          92 
#define BOXENGINE_KEY_RIGHT_BRACKET      93 
#define BOXENGINE_KEY_GRAVE_ACCENT       96 
#define BOXENGINE_KEY_WORLD_1            161
#define BOXENGINE_KEY_WORLD_2            162

/* Function keys */
#define BOXENGINE_KEY_ESCAPE             256
#define BOXENGINE_KEY_ENTER              257
#define BOXENGINE_KEY_TAB                258
#define BOXENGINE_KEY_BACKSPACE          259
#define BOXENGINE_KEY_INSERT             260
#define BOXENGINE_KEY_DELETE             261
#define BOXENGINE_KEY_RIGHT              262
#define BOXENGINE_KEY_LEFT               263
#define BOXENGINE_KEY_DOWN               264
#define BOXENGINE_KEY_UP                 265
#define BOXENGINE_KEY_PAGE_UP            266
#define BOXENGINE_KEY_PAGE_DOWN          267
#define BOXENGINE_KEY_HOME               268
#define BOXENGINE_KEY_END                269
#define BOXENGINE_KEY_CAPS_LOCK          280
#define BOXENGINE_KEY_SCROLL_LOCK        281
#define BOXENGINE_KEY_NUM_LOCK           282
#define BOXENGINE_KEY_PRINT_SCREEN       283
#define BOXENGINE_KEY_PAUSE              284
#define BOXENGINE_KEY_F1                 290
#define BOXENGINE_KEY_F2                 291
#define BOXENGINE_KEY_F3                 292
#define BOXENGINE_KEY_F4                 293
#define BOXENGINE_KEY_F5                 294
#define BOXENGINE_KEY_F6                 295
#define BOXENGINE_KEY_F7                 296
#define BOXENGINE_KEY_F8                 297
#define BOXENGINE_KEY_F9                 298
#define BOXENGINE_KEY_F10                299
#define BOXENGINE_KEY_F11                300
#define BOXENGINE_KEY_F12                301
#define BOXENGINE_KEY_F13                302
#define BOXENGINE_KEY_F14                303
#define BOXENGINE_KEY_F15                304
#define BOXENGINE_KEY_F16                305
#define BOXENGINE_KEY_F17                306
#define BOXENGINE_KEY_F18                307
#define BOXENGINE_KEY_F19                308
#define BOXENGINE_KEY_F20                309
#define BOXENGINE_KEY_F21                310
#define BOXENGINE_KEY_F22                311
#define BOXENGINE_KEY_F23                312
#define BOXENGINE_KEY_F24                313
#define BOXENGINE_KEY_F25                314
#define BOXENGINE_KEY_KP_0               320
#define BOXENGINE_KEY_KP_1               321
#define BOXENGINE_KEY_KP_2               322
#define BOXENGINE_KEY_KP_3               323
#define BOXENGINE_KEY_KP_4               324
#define BOXENGINE_KEY_KP_5               325
#define BOXENGINE_KEY_KP_6               326
#define BOXENGINE_KEY_KP_7               327
#define BOXENGINE_KEY_KP_8               328
#define BOXENGINE_KEY_KP_9               329
#define BOXENGINE_KEY_KP_DECIMAL         330
#define BOXENGINE_KEY_KP_DIVIDE          331
#define BOXENGINE_KEY_KP_MULTIPLY        332
#define BOXENGINE_KEY_KP_SUBTRACT        333
#define BOXENGINE_KEY_KP_ADD             334
#define BOXENGINE_KEY_KP_ENTER           335
#define BOXENGINE_KEY_KP_EQUAL           336
#define BOXENGINE_KEY_LEFT_SHIFT         340
#define BOXENGINE_KEY_LEFT_CONTROL       341
#define BOXENGINE_KEY_LEFT_ALT           342
#define BOXENGINE_KEY_LEFT_SUPER         343
#define BOXENGINE_KEY_RIGHT_SHIFT        344
#define BOXENGINE_KEY_RIGHT_CONTROL      345
#define BOXENGINE_KEY_RIGHT_ALT          346
#define BOXENGINE_KEY_RIGHT_SUPER        347
#define BOXENGINE_KEY_MENU               348

#define BOXENGINE_KEY_LAST               BOXENGINE_KEY_MENU

/*! @} */

/*! @defgroup mods Modifier key flags
 *  @brief Modifier key flags.
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

 /*! @brief If this bit is set one or more Shift keys were held down.
  *
  *  If this bit is set one or more Shift keys were held down.
  */
#define BOXENGINE_MOD_SHIFT           0x0001
  /*! @brief If this bit is set one or more Control keys were held down.
   *
   *  If this bit is set one or more Control keys were held down.
   */
#define BOXENGINE_MOD_CONTROL         0x0002
   /*! @brief If this bit is set one or more Alt keys were held down.
	*
	*  If this bit is set one or more Alt keys were held down.
	*/
#define BOXENGINE_MOD_ALT             0x0004
	/*! @brief If this bit is set one or more Super keys were held down.
	 *
	 *  If this bit is set one or more Super keys were held down.
	 */
#define BOXENGINE_MOD_SUPER           0x0008
	 /*! @brief If this bit is set the Caps Lock key is enabled.
	  *
	  *  If this bit is set the Caps Lock key is enabled and the @ref
	  *  BOXENGINE_LOCK_KEY_MODS input mode is set.
	  */
#define BOXENGINE_MOD_CAPS_LOCK       0x0010
	  /*! @brief If this bit is set the Num Lock key is enabled.
	   *
	   *  If this bit is set the Num Lock key is enabled and the @ref
	   *  BOXENGINE_LOCK_KEY_MODS input mode is set.
	   */
#define BOXENGINE_MOD_NUM_LOCK        0x0020

	   /*! @} */

	   /*! @defgroup buttons Mouse buttons
		*  @brief Mouse button IDs.
		*
		*  See [mouse button input](@ref input_mouse_button) for how these are used.
		*
		*  @ingroup input
		*  @{ */
#define BOXENGINE_MOUSE_BUTTON_1         0
#define BOXENGINE_MOUSE_BUTTON_2         1
#define BOXENGINE_MOUSE_BUTTON_3         2
#define BOXENGINE_MOUSE_BUTTON_4         3
#define BOXENGINE_MOUSE_BUTTON_5         4
#define BOXENGINE_MOUSE_BUTTON_6         5
#define BOXENGINE_MOUSE_BUTTON_7         6
#define BOXENGINE_MOUSE_BUTTON_8         7
#define BOXENGINE_MOUSE_BUTTON_LAST      BOXENGINE_MOUSE_BUTTON_8
#define BOXENGINE_MOUSE_BUTTON_LEFT      BOXENGINE_MOUSE_BUTTON_1
#define BOXENGINE_MOUSE_BUTTON_RIGHT     BOXENGINE_MOUSE_BUTTON_2
#define BOXENGINE_MOUSE_BUTTON_MIDDLE    BOXENGINE_MOUSE_BUTTON_3
		/*! @} */

		/*! @defgroup joysticks Joysticks
		 *  @brief Joystick IDs.
		 *
		 *  See [joystick input](@ref joystick) for how these are used.
		 *
		 *  @ingroup input
		 *  @{ */
#define BOXENGINE_JOYSTICK_1             0
#define BOXENGINE_JOYSTICK_2             1
#define BOXENGINE_JOYSTICK_3             2
#define BOXENGINE_JOYSTICK_4             3
#define BOXENGINE_JOYSTICK_5             4
#define BOXENGINE_JOYSTICK_6             5
#define BOXENGINE_JOYSTICK_7             6
#define BOXENGINE_JOYSTICK_8             7
#define BOXENGINE_JOYSTICK_9             8
#define BOXENGINE_JOYSTICK_10            9
#define BOXENGINE_JOYSTICK_11            10
#define BOXENGINE_JOYSTICK_12            11
#define BOXENGINE_JOYSTICK_13            12
#define BOXENGINE_JOYSTICK_14            13
#define BOXENGINE_JOYSTICK_15            14
#define BOXENGINE_JOYSTICK_16            15
#define BOXENGINE_JOYSTICK_LAST          BOXENGINE_JOYSTICK_16
		 /*! @} */

		 /*! @defgroup gamepad_buttons Gamepad buttons
		  *  @brief Gamepad buttons.
		  *
		  *  See @ref gamepad for how these are used.
		  *
		  *  @ingroup input
		  *  @{ */
#define BOXENGINE_GAMEPAD_BUTTON_A               0
#define BOXENGINE_GAMEPAD_BUTTON_B               1
#define BOXENGINE_GAMEPAD_BUTTON_X               2
#define BOXENGINE_GAMEPAD_BUTTON_Y               3
#define BOXENGINE_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define BOXENGINE_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define BOXENGINE_GAMEPAD_BUTTON_BACK            6
#define BOXENGINE_GAMEPAD_BUTTON_START           7
#define BOXENGINE_GAMEPAD_BUTTON_GUIDE           8
#define BOXENGINE_GAMEPAD_BUTTON_LEFT_THUMB      9
#define BOXENGINE_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define BOXENGINE_GAMEPAD_BUTTON_DPAD_UP         11
#define BOXENGINE_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define BOXENGINE_GAMEPAD_BUTTON_DPAD_DOWN       13
#define BOXENGINE_GAMEPAD_BUTTON_DPAD_LEFT       14
#define BOXENGINE_GAMEPAD_BUTTON_LAST            BOXENGINE_GAMEPAD_BUTTON_DPAD_LEFT

#define BOXENGINE_GAMEPAD_BUTTON_CROSS       BOXENGINE_GAMEPAD_BUTTON_A
#define BOXENGINE_GAMEPAD_BUTTON_CIRCLE      BOXENGINE_GAMEPAD_BUTTON_B
#define BOXENGINE_GAMEPAD_BUTTON_SQUARE      BOXENGINE_GAMEPAD_BUTTON_X
#define BOXENGINE_GAMEPAD_BUTTON_TRIANGLE    BOXENGINE_GAMEPAD_BUTTON_Y
		  /*! @} */

		  /*! @defgroup gamepad_axes Gamepad axes
		   *  @brief Gamepad axes.
		   *
		   *  See @ref gamepad for how these are used.
		   *
		   *  @ingroup input
		   *  @{ */
#define BOXENGINE_GAMEPAD_AXIS_LEFT_X        0
#define BOXENGINE_GAMEPAD_AXIS_LEFT_Y        1
#define BOXENGINE_GAMEPAD_AXIS_RIGHT_X       2
#define BOXENGINE_GAMEPAD_AXIS_RIGHT_Y       3
#define BOXENGINE_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define BOXENGINE_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define BOXENGINE_GAMEPAD_AXIS_LAST          BOXENGINE_GAMEPAD_AXIS_RIGHT_TRIGGER
		   /*! @} */

		   /*! @defgroup errors Error codes
			*  @brief Error codes.
			*
			*  See [error handling](@ref error_handling) for how these are used.
			*
			*  @ingroup init
			*  @{ */
			/*! @brief No error has occurred.
			 *
			 *  No error has occurred.
			 *
			 *  @analysis Yay.
			 */
#define BOXENGINE_NO_ERROR               0
			 /*! @brief BOXENGINE has not been initialized.
			  *
			  *  This occurs if a BOXENGINE function was called that must not be called unless the
			  *  library is [initialized](@ref intro_init).
			  *
			  *  @analysis Application programmer error.  Initialize BOXENGINE before calling any
			  *  function that requires initialization.
			  */
#define BOXENGINE_NOT_INITIALIZED        0x00010001
			  /*! @brief No context is current for this thread.
			   *
			   *  This occurs if a BOXENGINE function was called that needs and operates on the
			   *  current OpenGL or OpenGL ES context but no context is current on the calling
			   *  thread.  One such function is @ref BOXENGINESwapInterval.
			   *
			   *  @analysis Application programmer error.  Ensure a context is current before
			   *  calling functions that require a current context.
			   */
#define BOXENGINE_NO_CURRENT_CONTEXT     0x00010002
			   /*! @brief One of the arguments to the function was an invalid enum value.
				*
				*  One of the arguments to the function was an invalid enum value, for example
				*  requesting @ref BOXENGINE_RED_BITS with @ref BOXENGINEGetWindowAttrib.
				*
				*  @analysis Application programmer error.  Fix the offending call.
				*/
#define BOXENGINE_INVALID_ENUM           0x00010003
				/*! @brief One of the arguments to the function was an invalid value.
				 *
				 *  One of the arguments to the function was an invalid value, for example
				 *  requesting a non-existent OpenGL or OpenGL ES version like 2.7.
				 *
				 *  Requesting a valid but unavailable OpenGL or OpenGL ES version will instead
				 *  result in a @ref BOXENGINE_VERSION_UNAVAILABLE error.
				 *
				 *  @analysis Application programmer error.  Fix the offending call.
				 */
#define BOXENGINE_INVALID_VALUE          0x00010004
				 /*! @brief A memory allocation failed.
				  *
				  *  A memory allocation failed.
				  *
				  *  @analysis A bug in BOXENGINE or the underlying operating system.  Report the bug
				  *  to our [issue tracker](https://github.com/BOXENGINE/BOXENGINE/issues).
				  */
#define BOXENGINE_OUT_OF_MEMORY          0x00010005
				  /*! @brief BOXENGINE could not find support for the requested API on the system.
				   *
				   *  BOXENGINE could not find support for the requested API on the system.
				   *
				   *  @analysis The installed graphics driver does not support the requested
				   *  API, or does not support it via the chosen context creation backend.
				   *  Below are a few examples.
				   *
				   *  @par
				   *  Some pre-installed Windows graphics drivers do not support OpenGL.  AMD only
				   *  supports OpenGL ES via EGL, while Nvidia and Intel only support it via
				   *  a WGL or GLX extension.  macOS does not provide OpenGL ES at all.  The Mesa
				   *  EGL, OpenGL and OpenGL ES libraries do not interface with the Nvidia binary
				   *  driver.  Older graphics drivers do not support Vulkan.
				   */
#define BOXENGINE_API_UNAVAILABLE        0x00010006
				   /*! @brief The requested OpenGL or OpenGL ES version is not available.
					*
					*  The requested OpenGL or OpenGL ES version (including any requested context
					*  or framebuffer hints) is not available on this machine.
					*
					*  @analysis The machine does not support your requirements.  If your
					*  application is sufficiently flexible, downgrade your requirements and try
					*  again.  Otherwise, inform the user that their machine does not match your
					*  requirements.
					*
					*  @par
					*  Future invalid OpenGL and OpenGL ES versions, for example OpenGL 4.8 if 5.0
					*  comes out before the 4.x series gets that far, also fail with this error and
					*  not @ref BOXENGINE_INVALID_VALUE, because BOXENGINE cannot know what future versions
					*  will exist.
					*/
#define BOXENGINE_VERSION_UNAVAILABLE    0x00010007
					/*! @brief A platform-specific error occurred that does not match any of the
					 *  more specific categories.
					 *
					 *  A platform-specific error occurred that does not match any of the more
					 *  specific categories.
					 *
					 *  @analysis A bug or configuration error in BOXENGINE, the underlying operating
					 *  system or its drivers, or a lack of required resources.  Report the issue to
					 *  our [issue tracker](https://github.com/BOXENGINE/BOXENGINE/issues).
					 */
#define BOXENGINE_PLATFORM_ERROR         0x00010008
					 /*! @brief The requested format is not supported or available.
					  *
					  *  If emitted during window creation, the requested pixel format is not
					  *  supported.
					  *
					  *  If emitted when querying the clipboard, the contents of the clipboard could
					  *  not be converted to the requested format.
					  *
					  *  @analysis If emitted during window creation, one or more
					  *  [hard constraints](@ref window_hints_hard) did not match any of the
					  *  available pixel formats.  If your application is sufficiently flexible,
					  *  downgrade your requirements and try again.  Otherwise, inform the user that
					  *  their machine does not match your requirements.
					  *
					  *  @par
					  *  If emitted when querying the clipboard, ignore the error or report it to
					  *  the user, as appropriate.
					  */
#define BOXENGINE_FORMAT_UNAVAILABLE     0x00010009
					  /*! @brief The specified window does not have an OpenGL or OpenGL ES context.
					   *
					   *  A window that does not have an OpenGL or OpenGL ES context was passed to
					   *  a function that requires it to have one.
					   *
					   *  @analysis Application programmer error.  Fix the offending call.
					   */
#define BOXENGINE_NO_WINDOW_CONTEXT      0x0001000A
					   /*! @} */

					   /*! @addtogroup window
						*  @{ */
						/*! @brief Input focus window hint and attribute
						 *
						 *  Input focus [window hint](@ref BOXENGINE_FOCUSED_hint) or
						 *  [window attribute](@ref BOXENGINE_FOCUSED_attrib).
						 */
#define BOXENGINE_FOCUSED                0x00020001
						 /*! @brief Window iconification window attribute
						  *
						  *  Window iconification [window attribute](@ref BOXENGINE_ICONIFIED_attrib).
						  */
#define BOXENGINE_ICONIFIED              0x00020002
						  /*! @brief Window resize-ability window hint and attribute
						   *
						   *  Window resize-ability [window hint](@ref BOXENGINE_RESIZABLE_hint) and
						   *  [window attribute](@ref BOXENGINE_RESIZABLE_attrib).
						   */
#define BOXENGINE_RESIZABLE              0x00020003
						   /*! @brief Window visibility window hint and attribute
							*
							*  Window visibility [window hint](@ref BOXENGINE_VISIBLE_hint) and
							*  [window attribute](@ref BOXENGINE_VISIBLE_attrib).
							*/
#define BOXENGINE_VISIBLE                0x00020004
							/*! @brief Window decoration window hint and attribute
							 *
							 *  Window decoration [window hint](@ref BOXENGINE_DECORATED_hint) and
							 *  [window attribute](@ref BOXENGINE_DECORATED_attrib).
							 */
#define BOXENGINE_DECORATED              0x00020005
							 /*! @brief Window auto-iconification window hint and attribute
							  *
							  *  Window auto-iconification [window hint](@ref BOXENGINE_AUTO_ICONIFY_hint) and
							  *  [window attribute](@ref BOXENGINE_AUTO_ICONIFY_attrib).
							  */
#define BOXENGINE_AUTO_ICONIFY           0x00020006
							  /*! @brief Window decoration window hint and attribute
							   *
							   *  Window decoration [window hint](@ref BOXENGINE_FLOATING_hint) and
							   *  [window attribute](@ref BOXENGINE_FLOATING_attrib).
							   */
#define BOXENGINE_FLOATING               0x00020007
							   /*! @brief Window maximization window hint and attribute
								*
								*  Window maximization [window hint](@ref BOXENGINE_MAXIMIZED_hint) and
								*  [window attribute](@ref BOXENGINE_MAXIMIZED_attrib).
								*/
#define BOXENGINE_MAXIMIZED              0x00020008
								/*! @brief Cursor centering window hint
								 *
								 *  Cursor centering [window hint](@ref BOXENGINE_CENTER_CURSOR_hint).
								 */
#define BOXENGINE_CENTER_CURSOR          0x00020009
								 /*! @brief Window framebuffer transparency hint and attribute
								  *
								  *  Window framebuffer transparency
								  *  [window hint](@ref BOXENGINE_TRANSPARENT_FRAMEBUFFER_hint) and
								  *  [window attribute](@ref BOXENGINE_TRANSPARENT_FRAMEBUFFER_attrib).
								  */
#define BOXENGINE_TRANSPARENT_FRAMEBUFFER 0x0002000A
								  /*! @brief Mouse cursor hover window attribute.
								   *
								   *  Mouse cursor hover [window attribute](@ref BOXENGINE_HOVERED_attrib).
								   */
#define BOXENGINE_HOVERED                0x0002000B
								   /*! @brief Input focus on calling show window hint and attribute
									*
									*  Input focus [window hint](@ref BOXENGINE_FOCUS_ON_SHOW_hint) or
									*  [window attribute](@ref BOXENGINE_FOCUS_ON_SHOW_attrib).
									*/
#define BOXENGINE_FOCUS_ON_SHOW          0x0002000C

									/*! @brief Framebuffer bit depth hint.
									 *
									 *  Framebuffer bit depth [hint](@ref BOXENGINE_RED_BITS).
									 */
#define BOXENGINE_RED_BITS               0x00021001
									 /*! @brief Framebuffer bit depth hint.
									  *
									  *  Framebuffer bit depth [hint](@ref BOXENGINE_GREEN_BITS).
									  */
#define BOXENGINE_GREEN_BITS             0x00021002
									  /*! @brief Framebuffer bit depth hint.
									   *
									   *  Framebuffer bit depth [hint](@ref BOXENGINE_BLUE_BITS).
									   */
#define BOXENGINE_BLUE_BITS              0x00021003
									   /*! @brief Framebuffer bit depth hint.
										*
										*  Framebuffer bit depth [hint](@ref BOXENGINE_ALPHA_BITS).
										*/
#define BOXENGINE_ALPHA_BITS             0x00021004
										/*! @brief Framebuffer bit depth hint.
										 *
										 *  Framebuffer bit depth [hint](@ref BOXENGINE_DEPTH_BITS).
										 */
#define BOXENGINE_DEPTH_BITS             0x00021005
										 /*! @brief Framebuffer bit depth hint.
										  *
										  *  Framebuffer bit depth [hint](@ref BOXENGINE_STENCIL_BITS).
										  */
#define BOXENGINE_STENCIL_BITS           0x00021006
										  /*! @brief Framebuffer bit depth hint.
										   *
										   *  Framebuffer bit depth [hint](@ref BOXENGINE_ACCUM_RED_BITS).
										   */
#define BOXENGINE_ACCUM_RED_BITS         0x00021007
										   /*! @brief Framebuffer bit depth hint.
											*
											*  Framebuffer bit depth [hint](@ref BOXENGINE_ACCUM_GREEN_BITS).
											*/
#define BOXENGINE_ACCUM_GREEN_BITS       0x00021008
											/*! @brief Framebuffer bit depth hint.
											 *
											 *  Framebuffer bit depth [hint](@ref BOXENGINE_ACCUM_BLUE_BITS).
											 */
#define BOXENGINE_ACCUM_BLUE_BITS        0x00021009
											 /*! @brief Framebuffer bit depth hint.
											  *
											  *  Framebuffer bit depth [hint](@ref BOXENGINE_ACCUM_ALPHA_BITS).
											  */
#define BOXENGINE_ACCUM_ALPHA_BITS       0x0002100A
											  /*! @brief Framebuffer auxiliary buffer hint.
											   *
											   *  Framebuffer auxiliary buffer [hint](@ref BOXENGINE_AUX_BUFFERS).
											   */
#define BOXENGINE_AUX_BUFFERS            0x0002100B
											   /*! @brief OpenGL stereoscopic rendering hint.
												*
												*  OpenGL stereoscopic rendering [hint](@ref BOXENGINE_STEREO).
												*/
#define BOXENGINE_STEREO                 0x0002100C
												/*! @brief Framebuffer MSAA samples hint.
												 *
												 *  Framebuffer MSAA samples [hint](@ref BOXENGINE_SAMPLES).
												 */
#define BOXENGINE_SAMPLES                0x0002100D
												 /*! @brief Framebuffer sRGB hint.
												  *
												  *  Framebuffer sRGB [hint](@ref BOXENGINE_SRGB_CAPABLE).
												  */
#define BOXENGINE_SRGB_CAPABLE           0x0002100E
												  /*! @brief Monitor refresh rate hint.
												   *
												   *  Monitor refresh rate [hint](@ref BOXENGINE_REFRESH_RATE).
												   */
#define BOXENGINE_REFRESH_RATE           0x0002100F
												   /*! @brief Framebuffer double buffering hint.
													*
													*  Framebuffer double buffering [hint](@ref BOXENGINE_DOUBLEBUFFER).
													*/
#define BOXENGINE_DOUBLEBUFFER           0x00021010

													/*! @brief Context client API hint and attribute.
													 *
													 *  Context client API [hint](@ref BOXENGINE_CLIENT_API_hint) and
													 *  [attribute](@ref BOXENGINE_CLIENT_API_attrib).
													 */
#define BOXENGINE_CLIENT_API             0x00022001
													 /*! @brief Context client API major version hint and attribute.
													  *
													  *  Context client API major version [hint](@ref BOXENGINE_CONTEXT_VERSION_MAJOR_hint)
													  *  and [attribute](@ref BOXENGINE_CONTEXT_VERSION_MAJOR_attrib).
													  */
#define BOXENGINE_CONTEXT_VERSION_MAJOR  0x00022002
													  /*! @brief Context client API minor version hint and attribute.
													   *
													   *  Context client API minor version [hint](@ref BOXENGINE_CONTEXT_VERSION_MINOR_hint)
													   *  and [attribute](@ref BOXENGINE_CONTEXT_VERSION_MINOR_attrib).
													   */
#define BOXENGINE_CONTEXT_VERSION_MINOR  0x00022003
													   /*! @brief Context client API revision number attribute.
														*
														*  Context client API revision number
														*  [attribute](@ref BOXENGINE_CONTEXT_REVISION_attrib).
														*/
#define BOXENGINE_CONTEXT_REVISION       0x00022004
														/*! @brief Context robustness hint and attribute.
														 *
														 *  Context client API revision number [hint](@ref BOXENGINE_CONTEXT_ROBUSTNESS_hint)
														 *  and [attribute](@ref BOXENGINE_CONTEXT_ROBUSTNESS_attrib).
														 */
#define BOXENGINE_CONTEXT_ROBUSTNESS     0x00022005
														 /*! @brief OpenGL forward-compatibility hint and attribute.
														  *
														  *  OpenGL forward-compatibility [hint](@ref BOXENGINE_OPENGL_FORWARD_COMPAT_hint)
														  *  and [attribute](@ref BOXENGINE_OPENGL_FORWARD_COMPAT_attrib).
														  */
#define BOXENGINE_OPENGL_FORWARD_COMPAT  0x00022006
														  /*! @brief Debug mode context hint and attribute.
														   *
														   *  Debug mode context [hint](@ref BOXENGINE_OPENGL_DEBUG_CONTEXT_hint) and
														   *  [attribute](@ref BOXENGINE_OPENGL_DEBUG_CONTEXT_attrib).
														   */
#define BOXENGINE_OPENGL_DEBUG_CONTEXT   0x00022007
														   /*! @brief OpenGL profile hint and attribute.
															*
															*  OpenGL profile [hint](@ref BOXENGINE_OPENGL_PROFILE_hint) and
															*  [attribute](@ref BOXENGINE_OPENGL_PROFILE_attrib).
															*/
#define BOXENGINE_OPENGL_PROFILE         0x00022008
															/*! @brief Context flush-on-release hint and attribute.
															 *
															 *  Context flush-on-release [hint](@ref BOXENGINE_CONTEXT_RELEASE_BEHAVIOR_hint) and
															 *  [attribute](@ref BOXENGINE_CONTEXT_RELEASE_BEHAVIOR_attrib).
															 */
#define BOXENGINE_CONTEXT_RELEASE_BEHAVIOR 0x00022009
															 /*! @brief Context error suppression hint and attribute.
															  *
															  *  Context error suppression [hint](@ref BOXENGINE_CONTEXT_NO_ERROR_hint) and
															  *  [attribute](@ref BOXENGINE_CONTEXT_NO_ERROR_attrib).
															  */
#define BOXENGINE_CONTEXT_NO_ERROR       0x0002200A
															  /*! @brief Context creation API hint and attribute.
															   *
															   *  Context creation API [hint](@ref BOXENGINE_CONTEXT_CREATION_API_hint) and
															   *  [attribute](@ref BOXENGINE_CONTEXT_CREATION_API_attrib).
															   */
#define BOXENGINE_CONTEXT_CREATION_API   0x0002200B
															   /*! @brief Window content area scaling window
																*  [window hint](@ref BOXENGINE_SCALE_TO_MONITOR).
																*/
#define BOXENGINE_SCALE_TO_MONITOR       0x0002200C
																/*! @brief macOS specific
																 *  [window hint](@ref BOXENGINE_COCOA_RETINA_FRAMEBUFFER_hint).
																 */
#define BOXENGINE_COCOA_RETINA_FRAMEBUFFER 0x00023001
																 /*! @brief macOS specific
																  *  [window hint](@ref BOXENGINE_COCOA_FRAME_NAME_hint).
																  */
#define BOXENGINE_COCOA_FRAME_NAME         0x00023002
																  /*! @brief macOS specific
																   *  [window hint](@ref BOXENGINE_COCOA_GRAPHICS_SWITCHING_hint).
																   */
#define BOXENGINE_COCOA_GRAPHICS_SWITCHING 0x00023003
																   /*! @brief X11 specific
																	*  [window hint](@ref BOXENGINE_X11_CLASS_NAME_hint).
																	*/
#define BOXENGINE_X11_CLASS_NAME         0x00024001
																	/*! @brief X11 specific
																	 *  [window hint](@ref BOXENGINE_X11_CLASS_NAME_hint).
																	 */
#define BOXENGINE_X11_INSTANCE_NAME      0x00024002
																	 /*! @} */

#define BOXENGINE_NO_API                          0
#define BOXENGINE_OPENGL_API             0x00030001
#define BOXENGINE_OPENGL_ES_API          0x00030002

#define BOXENGINE_NO_ROBUSTNESS                   0
#define BOXENGINE_NO_RESET_NOTIFICATION  0x00031001
#define BOXENGINE_LOSE_CONTEXT_ON_RESET  0x00031002

#define BOXENGINE_OPENGL_ANY_PROFILE              0
#define BOXENGINE_OPENGL_CORE_PROFILE    0x00032001
#define BOXENGINE_OPENGL_COMPAT_PROFILE  0x00032002

#define BOXENGINE_CURSOR                 0x00033001
#define BOXENGINE_STICKY_KEYS            0x00033002
#define BOXENGINE_STICKY_MOUSE_BUTTONS   0x00033003
#define BOXENGINE_LOCK_KEY_MODS          0x00033004
#define BOXENGINE_RAW_MOUSE_MOTION       0x00033005

#define BOXENGINE_CURSOR_NORMAL          0x00034001
#define BOXENGINE_CURSOR_HIDDEN          0x00034002
#define BOXENGINE_CURSOR_DISABLED        0x00034003

#define BOXENGINE_ANY_RELEASE_BEHAVIOR            0
#define BOXENGINE_RELEASE_BEHAVIOR_FLUSH 0x00035001
#define BOXENGINE_RELEASE_BEHAVIOR_NONE  0x00035002

#define BOXENGINE_NATIVE_CONTEXT_API     0x00036001
#define BOXENGINE_EGL_CONTEXT_API        0x00036002
#define BOXENGINE_OSMESA_CONTEXT_API     0x00036003

/*! @defgroup shapes Standard cursor shapes
 *  @brief Standard system cursor shapes.
 *
 *  See [standard cursor creation](@ref cursor_standard) for how these are used.
 *
 *  @ingroup input
 *  @{ */

 /*! @brief The regular arrow cursor shape.
  *
  *  The regular arrow cursor.
  */
#define BOXENGINE_ARROW_CURSOR           0x00036001
  /*! @brief The text input I-beam cursor shape.
   *
   *  The text input I-beam cursor shape.
   */
#define BOXENGINE_IBEAM_CURSOR           0x00036002
   /*! @brief The crosshair shape.
	*
	*  The crosshair shape.
	*/
#define BOXENGINE_CROSSHAIR_CURSOR       0x00036003
	/*! @brief The hand shape.
	 *
	 *  The hand shape.
	 */
#define BOXENGINE_HAND_CURSOR            0x00036004
	 /*! @brief The horizontal resize arrow shape.
	  *
	  *  The horizontal resize arrow shape.
	  */
#define BOXENGINE_HRESIZE_CURSOR         0x00036005
	  /*! @brief The vertical resize arrow shape.
	   *
	   *  The vertical resize arrow shape.
	   */
#define BOXENGINE_VRESIZE_CURSOR         0x00036006
	   /*! @} */

#define BOXENGINE_CONNECTED              0x00040001
#define BOXENGINE_DISCONNECTED           0x00040002

/*! @addtogroup init
 *  @{ */
 /*! @brief Joystick hat buttons init hint.
  *
  *  Joystick hat buttons [init hint](@ref BOXENGINE_JOYSTICK_HAT_BUTTONS).
  */
#define BOXENGINE_JOYSTICK_HAT_BUTTONS   0x00050001
  /*! @brief macOS specific init hint.
   *
   *  macOS specific [init hint](@ref BOXENGINE_COCOA_CHDIR_RESOURCES_hint).
   */
#define BOXENGINE_COCOA_CHDIR_RESOURCES  0x00051001
   /*! @brief macOS specific init hint.
	*
	*  macOS specific [init hint](@ref BOXENGINE_COCOA_MENUBAR_hint).
	*/
#define BOXENGINE_COCOA_MENUBAR          0x00051002
	/*! @} */

#define BOXENGINE_DONT_CARE              -1

