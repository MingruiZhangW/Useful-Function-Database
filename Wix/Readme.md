# Wix - Example Code

**WixUI_Advanced**
- [Remove “Change” and “Repair” buttons in Add or Remove Programs](https://stackoverflow.com/questions/1741857/remove-change-and-repair-buttons-in-add-or-remove-programs)<br>

```
<Property Id="ARPNOREPAIR" Value="yes" Secure="yes" /> 
<Property Id="ARPNOMODIFY" Value="yes" Secure="yes" />
```
