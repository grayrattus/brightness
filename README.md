# Compile & install
```
sudo make install
```

# Usage

.Increase brightness by 100
```
sudo brightness 100
```

.Decrease brightness by 100
```
sudo brightness -100
```


Sadly to make this working you need to have root permissions. 
You can either put `sudo` and write password before each run or put:
```
your_user_name ALL=(ALL) NOPASSWD: /usr/bin/brightness
```
To run it with `sudo` but without need to type your password.

# Why?
I needed a simple program that will change brightness for my `dwm` window manager.
I'm pretty sure this won't work for all cases as hardware can be different
but for my HP laptop it's working fine.


