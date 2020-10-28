#ifndef HOOKS_H
# define HOOKS_H

# define KEYCODE_ESC 53
# define KEYCODE_RIGTARROW 124
# define KEYCODE_LEFTARROW 123
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2


int		hook_loop(void *param);
int		hook_key(int keycode, void *param);

#endif