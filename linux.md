# Linux Commands
————————————

### useful cmd apps

exa -> replacement for ls written in Rust.
fuck -> its give you a right command for you
How2 -> more colorful and readable than howdoi.
howdoi -> for information about programming.
cheatsh -> same job, more awesome and more harder than others..
Tldr -> Simplified and community-driven man pages.
https://www.shortcutfoo.com/ -> like academy !

For more https://github.com/oguzhanlarca/awesome-cli-apps

### Connect Wifi ->

Arch 
```
nmcli –ask device wifi connect FSOCIETY password wireless-password xxxxxxx
```
Mac
```
osx-wifi-cli --help
```

### Mac learn Wifi Pass ->

```
security find-generic-password -D "AirPort network password" -a FSOCIETY -g
```

### ssh

```
systemctl enable sshd.service
systemctl start sshd.service
```

### i3

By default, i3status looks for configuration files in the following order:
```
~/.config/i3status/config (or $XDG_CONFIG_HOME/i3status/config )
/etc/xdg/i3status/config (or $XDG_CONFIG_DIRS/i3status/config )
~/.i3status.conf
/etc/i3status.conf
```

### sensors -> https://wiki.archlinux.org/index.php/lm_sensors

Install the lm_sensors package.
```
sensors-detect
```
A systemd service is automatically enabled if users answer YES when asked about generating /etc/conf.d/lm_sensors. Answering YES also automatically starts the service.
```
sensors
```

### Reading SPD values from memory modules (optional)

To read the SPD timing values from memory modules, install the i2c-tools package. Once installed, load the eeprom kernel module.
```
modprobe eeprom
decode-dimms
```

### fan-speed
```
https://wiki.archlinux.org/index.php/Fan_speed_control
```

### yaourt
```
yaourt -Syu // To update Arch Linux system
yaourt -S <package-name> // To install a package
yaourt -U <package> // To upgrade/add packages
yaourt -R <package-name> // To remove a package
yaourt -P <directory> // To build package from PKGBUILD
yaourt --stats // To show the stats of the packages
man yaourt // For more details, check the man pages:
```

Note that the thinkfan package installs /usr/lib/modprobe.d/thinkpad_acpi.conf, which contains-> options thinkpad_acpi fan_control=1

```
echo "options thinkpad_acpi fan_control=1" > /etc/modprobe.d/thinkfan.conf
```

