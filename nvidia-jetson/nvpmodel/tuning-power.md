#How-To Adjust/tune NVIDIA Jetson power model (cmd):

Ref guide at: [developer.ridgerun.com][1]

1. Check current power mode:
    - `sudo /usr/sbin/nvpmodel -q`

2. Set new power mode:
    - `sudo /usr/sbin/nvpmodel -m <#1-8>`

3. Add extra definitions can be added in the file:
    - `sudo vim /etc/nvpmodel/nvpmodel_<#jetson_type>.conf`
        - The `<#jetson_type>` is:
            - `t186` for NVIDIA Jetson TX2 series
            - `t194` for NVIDIA JETSON AGX or NX Xavier series
            - `t210` for NVIDIA Jetson Nano or TX1 series

[1]: <https://developer.ridgerun.com/wiki/index.php/Xavier/JetPack_4.1/Performance_Tuning/Tuning_Power> "developer.ridgerun.com"
