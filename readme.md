# Add your keyboard into qmk repository as a subtree
❯ git clone https://github.com/qmk/qmk_firmware
❯ cd qmk_firmware
❯ git remote add -f keyboard_qmk https://github.com/girishji/keyboard_qmk.git

# Add subtree
❯ git subtree add --prefix=keyboards/girish keyboard_qmk main
<!-- ❯ git subtree add --prefix=keyboards/girish keyboard_qmk main --squash -->

# Pull changes for subtree
❯ git subtree pull --prefix=keyboards/girish keyboard_qmk main

# Commit to subtree directly
❯ git subtree push --prefix=keyboards/girish keyboard_qmk main
