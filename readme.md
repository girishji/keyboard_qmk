# Add your keyboard into qmk repository as a subtree
❯ git clone https://github.com/qmk/qmk_firmware
❯ cd qmk_firmware
❯ git remote add -f qmk_keyboard_girish https://github.com/girishji/qmk_keyboard_girish.git

# Add subtree
❯ git subtree add --prefix=keyboards/girish qmk_keyboard_girish main
<!-- ❯ git subtree add --prefix=keyboards/girish qmk_keyboard_girish main --squash -->

# Pull changes for subtree
❯ git subtree pull --prefix=keyboards/girish qmk_keyboard_girish main

# Commit to subtree directly
❯ git subtree push --prefix=keyboards/girish qmk_keyboard_girish main
