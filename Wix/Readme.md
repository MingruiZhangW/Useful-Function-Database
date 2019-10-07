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
