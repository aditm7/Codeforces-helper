tell application "System Preferences"
	set current pane to pane "com.apple.preference.keyboard"
end tell

tell application "System Events"
	if UI elements enabled then
		tell application process "System Preferences"
			repeat until exists tab group 1 of window "Keyboard"
				delay 0.5
			end repeat
			click radio button "Keyboard" of tab group 1 of window "Keyboard"
			click checkbox "Use F1, F2, etc. keys as standard function keys" of tab group 1 of window "Keyboard"
		end tell
		tell application "System Preferences" to quit
	else
		-- GUI scripting not enabled.  Display an alert
		tell application "System Preferences"
			activate
			set current pane to pane "com.apple.preference.security"
			display dialog "UI element scripting is not enabled. Please activate this app under Privacy -> Accessibility so it can access the settings it needs."
		end tell
	end if
end tell