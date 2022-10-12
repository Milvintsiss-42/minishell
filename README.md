# Minishell

Parsing to test:

```shell
> ls "-alh"
OUTPUT
[command output]
```

```shell
> ls "-a -l -h"
OUTPUT
ls: invalid option --
usage: ls [-@ABCFGHILOPRSTUWabcdefghiklmnopqrstuvwxy1%,] [--color=when] [-D format] [file ...]
```

```shell
> echo ls
OUTPUT
ls
```

```shell
> echo 'ls -alh'
OUTPUT
ls -alh
```

```shell
> cat ls
OUTPUT
cat: ls: No such file or directory
```

```shell
> "cat ls"
OUTPUT
bash: cat ls: command not found
```

```shell
> '\"ls | cat\"
OUTPUT
[heredoc]
```

```shell
> "echo" "$(touch test) and $(echo "hello" > test) then $(cat test)"
OUTPUT
 and  then hello
```

```shell
> ls (&& ls -alh)
OUTPUT
parse error near `)'
```
