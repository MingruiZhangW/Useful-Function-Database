# Wix - Example Code

**WixUI_Advanced**
- [Remove “Change” and “Repair” buttons in Add or Remove Programs](https://stackoverflow.com/questions/1741857/remove-change-and-repair-buttons-in-add-or-remove-programs)<br>

```
<Property Id="ARPNOREPAIR" Value="yes" Secure="yes" /> 
<Property Id="ARPNOMODIFY" Value="yes" Secure="yes" />
```

**Wix If define**
```
<?if $(var.App.Elevation) = perUser ?>
  <?define App.Privileges="limited" ?>
<?else?>
  <?define App.Privileges="elevated" ?>
<?endif ?>
```

**Wix Conditional Define** <br>
[In wix project](https://stackoverflow.com/questions/1688569/wix-howto-set-the-name-of-the-msi-output-file-dynamically)<br>

**Wix Exclude files When Harvesting**<br>
*Use an XSLT transform* - [see example code](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Wix/HarvestFilter.xslt)<br>

In wix project file
```
<HeatDirectory Directory="..\x64\Release" PreprocessorVariable="var.HarvestPath" OutputFile="Components.wxs" ComponentGroupName="HeatGenerated" DirectoryRefId="APPLICATIONFOLDER" AutogenerateGuids="true" ToolPath="$(WixToolPath)" SuppressFragments="true" SuppressRegistry="true" SuppressRootDirectory="true" Transforms="HarvestFilter.xslt" />
```
https://stackoverflow.com/questions/44765707/how-to-exclude-files-in-wix-toolset

**Wix Prebuild Harvesting**
- [Enabling Harvest (Heat.exe) in a Wix Setup Project](https://www.codeproject.com/Articles/1107786/Enabling-Harvest-Heat-exe-in-a-Wix-Setup-Project)<br>
