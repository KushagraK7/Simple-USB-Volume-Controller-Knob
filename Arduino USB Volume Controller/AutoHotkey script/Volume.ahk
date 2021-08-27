#Warn,UseUnsetLocal
#NoEnv
#SingleInstance force
SetBatchLines,-1



SoundGet,Volume
Volume:=Round(Volume)
TrayTip:="Alt+LeftArrow or Alt+RightArrow to adjust volume" . "`nCurrent Volume=" . Volume
TrayIconFile:=A_WinDir . "\System32\DDORes.dll" ; get tray icon from DDORes.dll
TrayIconNum:="-2032" ; use headphones as tray icon (icon 2032 in DDORes)
Menu,Tray,Tip,%TrayTip%
Menu,Tray,Icon,%TrayIconFile%,%TrayIconNum%
Return

^!Left::
Gui, Color, 00FA00
SetTimer,SliderOff,3000
SoundSet,-1
Gosub,DisplaySlider
Return

^!Right::
Gui, Color, 00FA00
SetTimer,SliderOff,3000
SoundSet,+1
Gosub,DisplaySlider
Return

SliderOff:
Progress,Off
Return

DisplaySlider:
SoundGet,Volume
Volume:=Round(Volume)
Progress,%Volume%,%Volume%,Volume,VolumeLevel
TrayTip:="Alt+LeftArrow or Alt+RightArrow to adjust volume" . "`nCurrent Volume=" . Volume
Menu,Tray,Tip,%TrayTip%
Return