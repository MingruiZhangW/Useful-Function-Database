# Windows Specific Knowledge

### Powershell

- [Powershell Download File](https://blog.jourdant.me/post/3-ways-to-download-files-with-powershell)<br>
- [PowerShell return value, exit code, or ErrorLevel equivalent](https://www.saotn.org/powershell-return-value-exit-code-or-errorlevel-equivalent/)<br>
- [Powershell Move Files](https://dotnet-helpers.com/powershell/how-to-move-files-from-one-location-to-another-location-using-powershell/)<br>
- [Powershell Wait For Process](https://stackoverflow.com/questions/43226877/wait-for-batch-file-to-finish-process-in-powershell-before-executing-other-comma)<br>
- [Powershell Find TEMP Folder](https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-find-the-temp-folder-path/)<br>
- [Powershell For Each](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_foreach?view=powershell-6)<br>
> Set Environment Var PATH Permentaly
```
$oldpath = (Get-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name PATH).path
$newpath = "$oldpath;;C:\tools\msys64\usr\bin;C:\Program Files\CMake"
Set-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name PATH -Value $newPath
```
