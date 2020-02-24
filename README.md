# Useful-Function-Database

**A personal collected reusable functions**

- [Binary Converter uint32_t x -> uint8_t *lit_int](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Binary%20Converter%20from%20uint32_t%20to%20uint8_t.md)
- [msgpack usage(map) pack of pack](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/msgpack%20usage(map)%20pack%20of%20pack.md)
- [WinGetEnv - Environment Vaiable Dir get method](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/WinGetEnv-Environment%20Variable%20Dir%20get%20method.md)
- [Dup - Print into a file](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Create_a_file_to_print.md)
- [Remove new lines in char string](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Remove_new_lines_in_char.md)
- [Regex - Find All Except a Specific Word](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Regex-Find%20All%20Except%20a%20Specific%20Word.md)<br>

[//]: # (Hello)
**QT**
- [QT - Block Signal Wrapper](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/QT%20Block%20Signal%20Wrapper%20(For%20Toggle%20Button%20and%20etc.).md)<br>
- [QT - Draw Rounded Edge Image](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/QT-Draw_Rounded_Edge_Photo.md)<br>
- [QT - Draw Black Circular Widget](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/QT%20-%20Draw%20Black%20Circular%20Widget.md)<br>

### Set Remote
https://help.github.com/en/articles/changing-a-remotes-url

### SSH KEY
https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key

# Git 
https://www.git-tower.com/blog/content/posts/54-git-cheat-sheet/git-cheat-sheet-large01.png<br>
- **Git: On undoing, fixing, or removing commits in git**
https://sethrobertson.github.io/GitFixUm/fixup.html#discard_all_unpushed

    Removing the last commit<br>
    To remove the last commit from git, you can simply run `git reset --hard HEAD^` If you are removing multiple commits from the top, you can run `git reset --hard HEAD~2` to remove the last two commits. You can increase the number to remove even more commits.

    If you want to "uncommit" the commits, but keep the changes around for reworking, remove the "--hard": `git reset HEAD^` which will evict the commits from the branch and from the index, but leave the working tree around.

    If you want to save the commits on a new branch name, then run git branch newbranchname before doing the git reset.

### Git Current Branch Name & Update brach 
https://stackoverflow.com/questions/3876977/update-git-branches-from-master/28505516 <br>
https://stackoverflow.com/questions/6245570/how-to-get-the-current-branch-name-in-git?rq=1 <br>
[Create New Branch](https://www.atlassian.com/git/tutorials/using-branches)<br>
https://remarkablemark.org/blog/2017/06/02/git-update-branch/
### Git Detached Head/Fetch Head
https://www.git-tower.com/learn/git/faq/detached-head-when-checkout-commit
https://stackoverflow.com/questions/9237348/what-does-fetch-head-in-git-mean

### Git - Find the commit that cause the bug
[Git bisect](https://git-scm.com/docs/git-bisect)<br>
> git bisect start<br>
git bisect bad --id<br>
git bisect good --id<br>
git bisect good/bad<br>
git bisect reset<br>

### Git - Origin Definition
[Git - what is origin](https://stackoverflow.com/questions/9529497/what-is-origin-in-git)

### Git - Delete Folder
https://github.community/t5/How-to-use-Git-and-GitHub/How-to-delete-multiples-files-in-Github/td-p/4623

### Git - Rebase
https://www.atlassian.com/git/tutorials/rewriting-history/git-rebase

### Git - stash apply vs stash pop
https://stackoverflow.com/questions/15286075/difference-between-git-stash-pop-and-git-stash-apply
```
git stash pop throws away the (topmost, by default) stash after applying it, whereas git stash apply leaves it in the stash list for possible later reuse (or you can then git stash drop it).<br>
This happens unless there are conflicts after git stash pop, in which case it will not remove the stash, leaving it to behave exactly like git stash apply.<br>
Another way to look at it: git stash pop is git stash apply && git stash drop<br>
```
### Git - Configure a fork & How to update/push to fork
- [Configure a remote for fork](https://help.github.com/en/articles/configuring-a-remote-for-a-fork)<br>
- [Syncing a fork](https://help.github.com/en/articles/syncing-a-fork)<br>
https://www.atlassian.com/git/tutorials/git-forks-and-upstreams
- [Push Commits](https://help.github.com/en/articles/pushing-commits-to-a-remote-repository)<br>
**Possible SSH ERROR**
>sign_and_send_pubkey: signing failed: agent refused operation
git@github.com: Permission denied (publickey).
fatal: Could not read from remote repository.

**Solution**
- https://askubuntu.com/questions/762541/ubuntu-16-04-ssh-sign-and-send-pubkey-signing-failed-agent-refused-operation <br>
- https://www.ssh.com/ssh/add <br>
- https://stackoverflow.com/questions/44250002/how-to-solve-sign-and-send-pubkey-signing-failed-agent-refused-operation <br>

### Git - update repo content
- [Git pull (with rebase)](https://www.atlassian.com/git/tutorials/syncing/git-pull)<br>
`git pull --rebase`

### Git - Submodules
- [Git submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules)<br>
```
You must run two commands: 
git submodule init 
to initialize your local configuration file, 
and 
git submodule update 
to fetch all the data from that project and check out the appropriate commit listed in your superproject

There is another way to do this which is a little simpler, 
If you pass --recurse-submodules to the git clone command,
it will automatically initialize and update each submodule in the repository,
including nested submodules if any of the submodules in the repository have submodules themselves.

If you already cloned the project and forgot --recurse-submodules,
you can combine the git submodule init and git submodule update steps by running
git submodule update --init.
To also initialize, fetch and checkout any nested submodules, you can use the foolproof
git submodule update --init --recursive.
```
**Update Submodules From upstream**
```
git submodule update --remote,
Git will go into your submodules and fetch and update for you.
```
### Git - Move Files
[Move Files](https://githowto.com/moving_files)<br>

### Git - Patch file (apply diff file)
[Patch file](https://medium.com/odds-team/create-a-patch-file-from-git-diff-c746be60d1e)<br>
https://gist.github.com/zeuxisoo/980174

## Git - Difference between origin master and origin/master
There are actually three things here: origin master is two separate things, and origin/master is one thing.<br>Three things total.<br>
Two branches:
- ```master``` is a local branch
- ```origin/master``` is a remote branch (which is a **local copy** of the branch named "master" on the remote named "origin")

[//]: # (Hello)
One remote:
- ```origin``` is a remote

> [Example](https://stackoverflow.com/questions/18137175/in-git-what-is-the-difference-between-origin-master-vs-origin-master)<br>
# Debug

### Using Visual Studio to attach processes
[Vs Debug](https://stackoverflow.com/questions/8167610/how-do-i-attach-visual-studio-to-a-process-that-is-not-started-yet)<br>
https://git.jami.net/savoirfairelinux/ring-project/issues/724#note_16719
### GDB Breakpoint insert
    gdb --args (binary)
    r 
    stop program
    break(b) full_filepath:line
    r(restart)
    Control + X + A(UI thread backtrace(bt))
    up/down/step
    info b
### GDB - Watch point
https://www.thegeekstuff.com/2014/02/gdb-breakpoins-watchpoints/<br>

### Debug - Turn off Optimizitaion
    #pragma optimize( "", off )
### Install - Apply WSL Terminal
[WSL](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/WSL-Windows%20Subsystem%20Linux/Readme.md)<br>
### Check Command History
[Command History](https://www.cyberciti.biz/faq/linux-unix-shell-history-search-command/)<br>
To get previous command containing string, hit [CTRL]+[r] followed by search string
