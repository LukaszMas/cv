#How-To Make jetson clocks persistent across reboots (cmd):

Ref guide at: [forums.developer.nvidia.com][1]

1. Make `jetson_clocks` script execution persistent across reboots
    - Crete `jetson_clocks.serivice`:
        - `sudo vim /etc/systemd/system/jetson_clocks.service`
    - Paste the following lines:
        - ```
          [Unit]
          Description=Maximize Jetson Performance
          After=multi-user.target

          [Service]
          ExecStart=/usr/bin/jetson_clocks

          [Install]
          WantedBy=multi-user.target
          ```
    - Enable the service:
        - `sudo systemctl daemon-reload`
        - `sudo systemctl enable jetson_clocks.service`
    - Start the service:
        - `sudo systemctl start jetson_clocks.service`
    - Check status of the service:
        - `sudo systemctl status jetson_clocks.service`

2. (opt) Another way is to update existing `nvpmodel.service`:
    - `sudo vim  /etc/systemd/system/nvpmodel.service`
    - Before `ExecStart=/usr/sbin/nvpmodel -f /etc/nvpmodel.conf` add the following:
    - `ExecStartPre=/usr/bin/jetson_clocks`

[1]: <https://forums.developer.nvidia.com/t/how-can-i-run-jetson-clocks-automatically-after-reboot-every-time/107249/2> "nvidia developers forum"
