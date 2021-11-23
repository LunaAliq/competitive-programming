# LunaAliq's Competitive Tools
```
Here
|- README.md
|- Makefile
|- new
|- tests
|- header
|- test-header
|- [sub directories]
|  |- Makefile
...
```

## README.md
This

## Makefile
### compile
```
make [name].o
```

### test
To test `[name].cpp` with `[name].test`

```
make test-[name]
```

`[name].test` is a file formated as following

```
#in([test-name])
[inputs]
[inputs]
...
[inputs]
#out([test-name])
[expected output]
...
[expected output]
#in([test-name])
...
```

It can contains multiple tests.

## new
script to make new cpp with `header` file.

```
$ new file-name.cpp
```

## tests
This is used by `Makefile`.

## header
cpp header. used by `new`

## test-header
tests of header. used by `Makefile`

## sub directories
must contains `Makefile` as following to use top directory's `Makefile`

```
%:
	make -f ../Makefile $@
```
