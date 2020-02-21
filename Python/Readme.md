# Python

### How to Execute Shell Commands with Python
[Os Module, Subprocess](https://janakiev.com/blog/python-shell-commands/)<br>
[SubProcess Return Code](https://stackoverflow.com/questions/5631624/how-to-get-exit-code-when-using-python-subprocess-communicate-method)<br>
```
import subprocess
child = subprocess.Popen(openRTSP + opts.split(), stdout=sp.PIPE)
streamdata = child.communicate()[0]
rc = child.returncode
```
