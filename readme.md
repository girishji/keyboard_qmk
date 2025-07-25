# Add this keyboard into qmk repository as a subtree
```
❯ git clone https://github.com/qmk/qmk_firmware
❯ cd qmk_firmware
❯ git remote add -f keyboard_qmk https://github.com/girishji/keyboard_qmk.git
❯ git subtree add --prefix=keyboards/girish keyboard_qmk main
```

# Make changes
```
> cd ~/git/qmk_firmware
> make girish/opticalkb/rev3
```

# Commit to subtree directly
```
# Make changes and then do this:
❯ git add .
❯ cd ~/git/qmk_firmware
❯ git subtree push --prefix=keyboards/girish keyboard_qmk main
```

# Pull changes for subtree (if necessary)
```
❯ git subtree pull --prefix=keyboards/girish keyboard_qmk main
```

