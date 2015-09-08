# Visual Studio 配置 OpenCV  

最近的工作需要在 Visual Studio 中调用 OpenCV，今天试着安装了一把。安装过程主要参考 [Librehat][Librehat] 同学的博文《[Visual Studio 2012下的OpenCV 2.4.7安装过程][1]》，也是这篇文章主要内容的来源。其实从名字就可以看出，本文是对其的致敬（抄袭)，外加一些自己遇到的小麻烦，以方便日后的再次安装。

## 1. 素材的准备
说是素材，无非就是 Visual Studio 和 OpenCV。Librehat 同学不推荐使用Express版本，但禁不住它体积小，对于我的需求来说足够了，所以我最后选了 Visual Studio Express 2012；OpenCV 的版本是 2.4.10。

## 2. OpenCV文件夹的准备
直接引用 Librehat 的文字：
> 官网下载最新OpenCV的Windows安装程序（其实是一个自解压包），200+MB的体积，双击解压缩到某个分区（如果是SSD的话建议先解压到某个移动硬盘上），并不是所有文件都是需要的。对于32位Windows系统只需要build文件夹下的以下文件：
![](https://www.librehat.com/wp-content/uploads/2013/11/buildfiles.jpg)
> 如果是64位Windows系统和64位Visual Studio则需要x64文件夹而不是x86文件夹。而且，x86/x64文件夹下，只需要vc11这个文件夹，不需要vc10（vc11对应VS2012，vc10对应VS2010）。这样一来可以为SSD减轻负担，在D盘创建文件夹openCV_build，把以上需要的build下的文件夹拷贝进去（对于32位系统，openCV_build的内容就和上面截图所示一样）。

需要注意的是， Librehat 这里说的是 64 位Windows系统和 64 位 Visual Studio，但不是在 64 位Windows系统跑的就是 64 位 Visual Studio，要在确认自己的 Visual Studio 究竟是 32 位还是 64 位后，再选择采用 x86 文件夹还是 x64 文件夹。不过我记得 Visual Studio 目前只有 32 位版本，64 位系统也是安装 32位 版本的 Visual Studio 的。

## 3. 设置环境变量
直接引用 Librehat 的文字：
> 打开管理员模式的命令提示符，运行：
```bash
setx -m OPENCV_DIR D:\openCV_build\x86\vc11
```
> -m参数表示该环境变量属于系统范围而非用户范围的值，稍等片刻待提示值已保存后可以关闭cmd了。然后打开计算机属性->高级系统设置->设置环境变量。
> 在系统变量里找到Path，双击修改，在末尾添加OpenCV的bin（记住要用半角分号隔开），
```bash
%OPENCV_DIR%\bin
```
> 如下图所示。使用%OPENCV_DIR%变量的好处是万一下次要变动OpenCV（比如安装了两个版本的OpenCV或者改变了路径），只需要修改%OPENCV_DIR%这个变量即可。
![](https://www.librehat.com/wp-content/uploads/2013/11/system_variable.jpg)

如果你是 64 位系统的 Visual Studio，那么上面那条命令就是 x64 啦。

## 4. Visual Studio的配置
直接引用 Librehat 的文字：
> 以Visual Studio 2012和官方指南的Local Method（本地方法）为例，修改某一个工程的属性，添加依赖。（VS2012的项目下的VC++目录功能被否决，无法再用全局方法修改了）
 > 右键单击项目->属性，把弹出窗口左上角的配置更改为“**所有配置**(**All Configurations**)”，选择**配置属性**(**Configuration Properties**)->**VC++目录**(**VC++ Directories**)，更改右边的**包含目录**(**Include Directories**)，**编辑**(**Edit**)，新加一行：

```bash
$(OPENCV_DIR)\..\..\include
```
> 类似地，更改**库目录**(**Library Directories**)，新加一行：

```bash
$(OPENCV_DIR)\lib
```
> 如下图所示。
![](https://www.librehat.com/wp-content/uploads/2013/11/vs_settings_inc_lib.jpg)
> 现在修改**Debug**配置的属性表，在**链接器**(**Linker**)->**输入**(**Input**)下，修改**附加依赖项**(**Additional Dependencies**)。这里应该包含所有你需要的OpenCV模块，模块的名称规则是opencv_<module_name><version_number>d.lib，全部模块如下（OpenCV 2.4.10）：
```bash
opencv_core2410d.lib
opencv_imgproc2410d.lib
opencv_highgui2410d.lib
opencv_ml2410d.lib
opencv_video2410d.lib
opencv_features2d2410d.lib
opencv_calib3d2410d.lib
opencv_objdetect2410d.lib
opencv_contrib2410d.lib
opencv_legacy2410d.lib
opencv_flann2410d.lib
opencv_nonfree2410d.lib
```
> 然后在**Release**的配置下再来一次，这一次不要版本号后面的d（d表示debug），完整的模块列表如下：
```bash
opencv_core2410.lib
opencv_imgproc2410.lib
opencv_highgui2410.lib
opencv_ml2410.lib
opencv_video2410.lib
opencv_features2d2410.lib
opencv_calib3d2410.lib
opencv_objdetect2410.lib
opencv_contrib2410.lib
opencv_legacy2410.lib
opencv_flann2410.lib
opencv_nonfree2410.lib
```
Librehat 用的是 2.4.7 版本的 OpenCV，而我用的是 2.4.10，只要随便找个编辑器把上述库末尾的 247 替换成 2410 即可（为了偷懒我已经替换了）。另外，我添加了 opencv_nonfree2410，否则在日后使用到 SIFT \ SURF 等算法时，可能会遇到 `error LNK2019: unresolved external symbol "bool __cdecl cv::initModule_nonfree(void)"`这个问题。

## 5. 编译测试工程
下面是我自己写的一份测试代码，如果你是把 openCV_build 文件夹放在了 D 盘，那应该能够正常显示：

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
 
int main(int argc, char **argv)
{ 
    std::string imgPathStr("D:\\openCV_build\\doc\\opencv-logo2.png");
    cv::Mat img = cv::imread(imgPathStr,-1); // Read image
    cv::imshow("img",img);
    cv::waitKey();
    std::system("PAUSE");
    return 0;
}
```

## 6. 遇到的问题
按照上面的流程，在运行测试工程代码的时候我还是遇到了两个问题：
##### 问题一：无法找到 opencv.hpp
问题一让人很沮丧，我明明刚把这路径添加进去，怎么就找不到呢？遇到这种情况不要急，把刚才设置环境变量的 cmd 窗口关闭，再把 Visual Studio 关闭并重新打开试试，我就是这么干就好了。也许，Visual Studio 是每次在打开工程是读取这些配置的，你刚刚设置的它还来不及读取。
##### 问题二：error LNK1112: module machine type 'x64' conflicts with target machine type 
问题二的原因就是在于，在 64 位的 Windows 上也可能运行 32 位的 Visual Studio，总之我的这个就是。证据是 Visual Studio 的安装目录，就是在 D 盘的 Program Files (x86) 文件夹下，而不是像一般 64 位软件安装于 Program Files 目录。找到了病因，我们只要把环境变量重新设置成 x86 目录即可，也就是只需重新以管理员身份在 cmd 窗口中输入下面这条命令即可：

```bash
setx -m OPENCV_DIR D:\openCV_build\x86\vc11
```
其余都不需要做，比如改动 Visual Studio 里的那些设置，因为这就是环境变量的好处。

##### 问题三：error LNK2019: unresolved external symbol "bool __cdecl cv::initModule_nonfree(void)
这个问题在上面的测试代码运行中并不会出现，主要是在使用类似于 SIFT\SURF 等在 nonfree 模块下的算法时出现的。这个出现的原因在于我们没有将 opencv_nonfree2410d.lib 和 opencv_nonfree2410.lib 分别加入 Debug 和 Release 配置的属性表，在**链接器**(**Linker**)->**输入**(**Input**)下，修改**附加依赖项**(**Additional Dependencies**)，分别添加这两个就可以了。为了方便起见，我已经在上面配置的时候添加了这两项。

初写于 2015-03-26，更新于 2015-08-20.
首发于 [Yimian Dai's Homepage]，转载请注明出处。

## 参考文献：
1. [Librehat - Visual Studio 2012下的OpenCV 2.4.7安装过程][1]

[Librehat]: https://www.librehat.com
[1]: https://www.librehat.com/visual-studio-2012-with-opencv-2-4-7-installation/
[Yimian Dai's Homepage]: http://dym.mobi/