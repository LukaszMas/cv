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
   - (opt) During `dist-upgrade` some of JetPack Debian packages are removed,  
     other may not be updated, a workound is to after `apt dist-upgrade` run:
        - `sudo apt install nvidia-jetpack`

2. Re-log the <username> to activate the changes

3. If you endub with an ERROR: "Procedure for bootloader update FAILED"
    - run the following:
        - `sudo mv /var/lib/dpkg/info/ /var/lib/dpkg/info_old/`
        - `sudo mkdir /var/lib/dpkg/info/`
        - `sudo apt-get update`
        - `sudo apt-get -f install`
        - `sudo mv /var/lib/dpkg/info/* /var/lib/dpkg/info_old/`
        - `sudo rm -rf /var/lib/dpgk/info`
        - `sudo mv /var/lib/dpkg/info_old/ /var/lib/dpkg/info/`
    - Now you should be able to run the following:
        - `sudo apt-get update`
        - `sudo apt-get upgrade`
    - Resource: [Aidam_Bo blog][6]

4. Useful commands:
    - To check if rootfs redundancy A/B is active:
        - `sudo nvbootctrl -t rootfs dump-slots-info`
    - To enable rootfs A/B:
        - `sudo nv_update_engine --enable-ab`
    - To disable rootfs A/b:
        - `sudo nv_update_engine --disable-ab`
    - To mark the rootfs slot as unbootable use:
        - `l4t-rootfs-validation-config.sh`

5. Additional resources:
    - [Nvidia developers forum1][2]
    - [Nvidia developers forum2][3]
    - [Nvidia developers forum3][4]
    - [Nvidia docs][5]

[1]: <https://docs.nvidia.com/jetson/archives/l4t-archived/l4t-3261/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/updating_jetson_and_host.html#wwpID0E0OK0HA> "nvidia docs"
[2]: <https://forums.developer.nvidia.com/t/when-and-by-which-software-component-a-b-rootfs-boot-retry-count-is-decremented/197124/7> "nvidia developers forum"
[3]: <https://forums.developer.nvidia.com/t/i-want-to-check-if-a-b-system-update-is-available/209341/12> "nvidia developers forum"
[4]: <https://forums.developer.nvidia.com/t/enable-filesystem-a-b/200163> "nvidia developers forum"
[5]: <https://docs.nvidia.com/jetson/archives/l4t-archived/l4t-3261/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/rootfs_custom.html#wwpID0E0GE0HA> "nvidia developers forum"
[6]: <https://blog.csdn.net/Aidam_Bo/article/details/110091337> "Adam_bo blog article"
