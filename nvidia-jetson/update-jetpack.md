#How-To Update Nvidia JetPack version (cmd):

Ref guide at: [nvidia docs][1]

1. To update t oa new minor release:
    - `sudo vi /etc/apt/sources.list.d/nvidia-l4t-apt-source.list`
    - Change the repository name for deb packages:
        -```
         deb https://repo.download.nvidia.com/jetson/common <release> main
         deb https://repo.download.nvidia.com/jetson/<platform> <release> main
         ```
            - <platform> identifies the platform’s processor:
              ```
              t186 for NVIDIA® Jetson™ TX2 series
              t194 for NVIDIA® Jetson AGX Xavier™ series or Jetson Xavier NX
              t210 for NVIDIA® Jetson Nano™ devices or Jetson TX1
              ```
   - Run the commands:
   - `sudo apt update`
   - `sudo apt dist-upgrade`

2. Re-log the <username> to activate the changes

[1]: <https://docs.nvidia.com/jetson/archives/l4t-archived/l4t-3261/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/updating_jetson_and_host.html#wwpID0E0OK0HA> "nvidia docs"
