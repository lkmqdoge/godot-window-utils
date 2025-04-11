extends Node2D

@onready var button_set: Button = %"ButtonSet"
@onready var button_clear: Button = %"ButtonClear"
@onready var button_ts_hide: Button = %"ButtonTSHide"
@onready var button_ts_show: Button = %"ButtonTSShow"

func _ready() -> void:
	button_set.pressed.connect(
		func():
			WindowUtils.set_transparent(DisplayServer.window_get_native_handle(DisplayServer.HandleType.WINDOW_HANDLE))
	)

	button_clear.pressed.connect(
		func():
			WindowUtils.clear_transparent(DisplayServer.window_get_native_handle(DisplayServer.HandleType.WINDOW_HANDLE))
	)

	button_ts_hide.pressed.connect(
		func():
			WindowUtils.taskbar_hide(DisplayServer.window_get_native_handle(DisplayServer.HandleType.WINDOW_HANDLE))
	)

	button_ts_show.pressed.connect(
		func():
			WindowUtils.taskbar_show(DisplayServer.window_get_native_handle(DisplayServer.HandleType.WINDOW_HANDLE))
	)
