Dim shell, commande
Set shell = WScript.CreateObject("WScript.Shell")
commande="launch.bat"
shell.Run commande, 0,true
WScript.quit