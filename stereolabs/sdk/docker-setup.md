# How-to Set ZED camera inside docker

1. Making sure [dynamic plug][1] works inside docker:
    - mount `/dev` volume
    - add env variable: `--environment UDEV=1`

2) Make sure Zed is connected to the USB3 port, [zed-issue][2]

[1]: <https://forums.balena.io/t/docker-container-cannot-access-dynamically-plugged-usb-devices/4277/14> "forums.blena.io"
[2]: <https://github.com/stereolabs/zed-ros-wrapper/issues/548 "stereolabs-git"
