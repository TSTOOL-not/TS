#选择服务大区
function xuan {
PS3='选择你要的服务区域，若果没有进入请换区域 : '
echo "链接主机地址为:154.40.47.96"
sleep 2
options=("关山酒恋第一服务区" "荒天帝第二服务区" "退出")
select opt in "${options[@]}"
do
 case $opt in
    "关山酒恋第一服务区")
      guan
     ;;
    "荒天帝第二服务区")
      huang
    ;;
     "退出")
     tui
     ;;
     *) echo "invalid option $REPLY";;
  esac
done
}
# 检查mplayer是否安装
if ! command -v mplayer &> /dev/null
then
    echo "找不到mplayer，请先安装." >&2
    exit 1
fi
# 播放指定的音乐文件并隐藏所有输出
mplayer -quiet /data/user/0/com.termux/files/home/TS/music/欢迎语.mp3 >/dev/null 2>&1 &
sleep 1
function Coloring {
    NC='\033[0m'
    LRED='\033[1;31m'
    LGREEN='\033[1;32m'
    YELLOW='\033[1;33m'
    PURPLE='\033[1;35m'
    LBLUE='\033[1;36m'
    LIGHTPURPLE='\033[1;35m'
}

# BANNER
banner() {
clear
echo -e "

████████╗███████╗    ████████╗ ██████╗  ██████╗ ██╗     
╚══██╔══╝██╔════╝    ╚══██╔══╝██╔═══██╗██╔═══██╗██║     
   ██║   ███████╗       ██║   ██║   ██║██║   ██║██║     
   ██║   ╚════██║       ██║   ██║   ██║██║   ██║██║     
   ██║   ███████║       ██║   ╚██████╔╝╚██████╔╝███████╗
   ╚═╝   ╚══════╝       ╚═╝    ╚═════╝  ╚═════╝ ╚══════╝

${YELLOW} -------------------------------------------------------------------
 更新中..."
 
}
sleep 1
mplayer -quiet /data/user/0/com.termux/files/home/TS/music/背景音乐.mp3 >/dev/null 2>&1 &
mkdir -p /sdcard/Download/TS/obb
# Directory checks
check_directories() {
    mkdir -p /sdcard/Download/TS/
}
mkdir -p /sdcard/Download/TS/需要搜索的解包值

UNPACK="/sdcard/Download/TS/"
REPACK="/sdcard/Download/TS/$base_name/REPACK"

# FUNCTION UNPACK TS NON CHUNK
unpackingnonchunks() {
    base_name=$(basename "$selected_file" .pak)
    OUTPUTNC="/sdcard/Download/TS/$base_name/非块/"
    REPACK="/sdcard/Download/TS/$base_name/REPACK/"


    if [ ! -f "$selected_file" ]; then
        echo -e "${LRED}Error: File $selected_file not found!${NC}"
        exit 1
    fi

    mkdir -p "$OUTPUTNC"
    echo "Created folder $OUTPUTNC"

    # Unpack the PAK file without chunking
    cd /data/user/0/com.termux/files/usr/bin
    if ./tsun -a "$UNPACK/$(basename "$selected_file")" "$OUTPUTNC"; then
        clear
        sleep 1.5
        echo "云端服务器解包成功，服务器已经记录"
        

        mkdir -p "$REPACK"
        echo "Created folder $REPACK"
    else
        echo -e "${LRED}Error: Unpacking of $selected_file failed!${NC}"
        
    fi
}

#关山酒恋服务器
function guan {
clear
echo "你选择了关山酒恋第一服务区 此服务器可容纳30人，文件传输速度拉满"
sleep 1
echo "链接服务器..."
sleep 2
! ping -c 1 223.5.5.5 >/dev/null 2>&1 && echo 验证阿里DNS失败，请更换网络 && exit 1
echo "链接成功，正在加载TS"
banner
main
}
#荒天帝区域
function huang {
clear
echo "你选择了荒天帝第二服务区 此服务器可容纳15人，文件传输速度拉满"
sleep 1
echo "链接服务器..."
sleep 2
! ping -c 1 223.5.5.5 >/dev/null 2>&1 && echo 验证阿里DNS失败，请更换网络 && exit 1
echo "链接成功，正在加载TS"
banner
main
}

# FUNCTION UNPACK TS CHUNKS
unpackingchunks() {
    base_name=$(basename "$selected_file" .pak)
    OUTPUTC="/sdcard/Download/TS/$base_name/块/"
    REPACK="/sdcard/Download/TS/$base_name/REPACK/"

    
    if [ ! -f "$selected_file" ]; then
        echo -e "${LRED}Error: File $selected_file not found!${NC}"
        exit 1
    fi

    mkdir -p "$OUTPUTC"
    echo "Created folder $OUTPUTC"

    # Unpack the PAK file with chunking
    cd /data/user/0/com.termux/files/usr/bin
    if ./tsun -a -c 65536 "$UNPACK/$(basename "$selected_file")" "$OUTPUTC"; then
        echo "Unpacking completed successfully."
        
        
        mkdir -p "$REPACK"
        echo "Created folder $REPACK"
    else
        echo -e "${LRED}Error: Unpacking of $selected_file failed!${NC}"
        exit 1
    fi
}



# FUNCTION REPACK TS
repackingpaks() {
    base_name=$(basename "$selected_file" .pak)
    REPACK="/sdcard/Download/TS/$base_name/REPACK/"
    
    # Tạo thư mục REPACK nếu chưa tồn tại
    mkdir -p "$REPACK"
    
    # Tiến hành repacking
   cd /data/user/0/com.termux/files/usr/bin
    if ./fei -a -r "$selected_file" "$REPACK"; then
        # Kiểm tra xem tệp PAK mới có tồn tại không
        REPACKED_FILE="$REPACK/$base_name.pak"
        if [ ! -f "$REPACKED_FILE" ]; then
            exit 1
        fi
    else
        exit 1
    fi
}
mei() {
cd /data/user/0/com.termux/files/home/MeiPro
./MeiHua
}
kuaiing() {
    base_name=$(basename "$selected_file" .pak)
    REPACK="/sdcard/Download/TS/$base_name/块打包/"
    
    # Tạo thư mục REPACK nếu chưa tồn tại
    mkdir -p "$REPACK"
    
    # Tiến hành repacking
    cd /data/user/0/com.termux/files/usr/bin
    if ./tsre -k -n -j 65536 "$selected_file" "$REPACK"; then
        # Kiểm tra xem tệp PAK mới có tồn tại không
        REPACKED_FILE="$REPACK/$base_name.pak"
        if [ ! -f "$REPACKED_FILE" ]; then
            exit 1
        fi
    else
        exit 1
    fi
}
map() {
./unpackmap
}
function tsobb {
./obb1
}
# FUNCTION START UNPACK TS NON CHUNK
function unpacknonchunks {
    prompt="输入你的选择:"
    options=($(find /sdcard/Download/TS -name "*.pak" 2>/dev/null))
    
    if [ ${#options[@]} -eq 0 ]; then
        echo -e "${LRED}No .pak files found in UNPACK directory.${NC}"
        return
    fi

    PS3="$prompt "
    select opt in "${options[@]}" "Back"; do
        if (( REPLY == 1 + ${#options[@]} )); then
            break
        elif (( REPLY > 0 && REPLY <= ${#options[@]} )); then
            selected_file="${options[$REPLY-1]}"
            echo "You picked $selected_file which is file $REPLY"
            unpackingnonchunks
            echo "File is saved at: $OUTPUTNC"      
            exit    
        else
            echo "Invalid option. Try another one."
        fi
    done
}
function sou {
  
  search_results=( $(grep -ril "$C_Recoil_" /sdcard/Download/TS/需要搜索的解包值) )

      if [ ${#search_results[@]} -eq 0 ]; then
    echo "No matching files found."
  else
    echo "Matching files:"
    for ((i=0; i<${#search_results[@]}; i++)); do
      
      if [ $i -eq 0 ]; then
        echo -e "\e[32m$(($i+1)): $(basename "${search_results[$i]}")\e[0m"
      else
        echo "$(($i+1)): $(basename "${search_results[$i]}")"
      fi
    done

    all_files_option="All"
    quit_option="Quit"
    copy_all_option="Copy All"
    options=("Select One" "$all_files_option" "$copy_all_option" "$quit_option")
    selected_files=()

    while true; do
      read -p "输入要添加到选择中的文件号（例如2,5,6,4），“a”选择全部，或“q”退出： " choice

      if [ "$choice" = "q" ]; then
        echo "Operation canceled."
        break
      elif [ "$choice" = "a" ]; then
        selected_files=("${search_results[@]}")
        echo "All files selected."
        break
      else
        IFS=',' read -ra file_numbers <<< "$choice"

        for num in "${file_numbers[@]}"; do
          if [ "$num" -ge 1 ] && [ "$num" -le ${#search_results[@]} ]; then
            selected_files+=("${search_results[$((num-1))]}")
            echo "File '$(basename "${search_results[$((num-1))]}")' added to selection."
          else
            echo "Invalid file number '$num'. Try another one."
          fi
        done
      fi
    done

    if [ "${#selected_files[@]}" -eq 0 ]; then
      echo "No files selected for copying."
    else
      echo "Selected files:"
      for file in "${selected_files[@]}"; do
        echo "- $(basename "$file")"
      done

      Finded_Files="/sdcard/Download/TS/搜索结果/"
      if [ ! -d "$Finded_Files" ]; then
        mkdir -p "$Finded_Files"
        echo "Created directory '$Finded_Files'."
      fi

      read -p "输入“c”复制所有选定文件，或输入“q”退出： " copy_option
      if [ "$copy_option" = "c" ]; then
        for file in "${selected_files[@]}"; do
          cp "$file" "$Finded_Files/"
          echo "File '$(basename "$file")' copied to the destination directory."
        done
      else
        echo "Operation canceled."
      fi
    fi
  fi


}

 function 3 {
   
  search_results=( $(grep -ril "$C_Recoil_SCAR" /sdcard/Download/TS/需要搜索的解包值) )

      if [ ${#search_results[@]} -eq 0 ]; then
    echo "No matching files found."
  else
    echo "Matching files:"
    for ((i=0; i<${#search_results[@]}; i++)); do
      
      if [ $i -eq 0 ]; then
        echo -e "\e[32m$(($i+1)): $(basename "${search_results[$i]}")\e[0m"
      else
        echo "$(($i+1)): $(basename "${search_results[$i]}")"
      fi
    done

    all_files_option="All"
    quit_option="Quit"
    copy_all_option="Copy All"
    options=("Select One" "$all_files_option" "$copy_all_option" "$quit_option")
    selected_files=()

    while true; do
      read -p "输入要添加到选择中的文件号（例如2,5,6,4），“a”选择全部，或“q”退出： " choice

      if [ "$choice" = "q" ]; then
        echo "Operation canceled."
        break
      elif [ "$choice" = "a" ]; then
        selected_files=("${search_results[@]}")
        echo "All files selected."
        break
      else
        IFS=',' read -ra file_numbers <<< "$choice"

        for num in "${file_numbers[@]}"; do
          if [ "$num" -ge 1 ] && [ "$num" -le ${#search_results[@]} ]; then
            selected_files+=("${search_results[$((num-1))]}")
            echo "File '$(basename "${search_results[$((num-1))]}")' added to selection."
          else
            echo "Invalid file number '$num'. Try another one."
          fi
        done
      fi
    done

    if [ "${#selected_files[@]}" -eq 0 ]; then
      echo "No files selected for copying."
    else
      echo "Selected files:"
      for file in "${selected_files[@]}"; do
        echo "- $(basename "$file")"
      done

      Finded_Files="/sdcard/Download/TS/搜索结果/SCAR"
      if [ ! -d "$Finded_Files" ]; then
        mkdir -p "$Finded_Files"
        echo "Created directory '$Finded_Files'."
      fi

      read -p "输入“c”复制所有选定文件，或输入“q”退出： " copy_option
      if [ "$copy_option" = "c" ]; then
        for file in "${selected_files[@]}"; do
          cp "$file" "$Finded_Files/"
          echo "File '$(basename "$file")' copied to the destination directory."
        done
      else
        echo "Operation canceled."
      fi
    fi
  fi
  }
# FUNCTION START UNPACK TS CHUNKS
function unpackchunks {
    
    prompt="输入你的选择:"
    options=($(find /sdcard/Download/TS -name "*.pak" 2>/dev/null))
    
    if [ ${#options[@]} -eq 0 ]; then
        echo -e "${LRED}No .pak files found in UNPACK directory.${NC}"
        return
    fi

    PS3="$prompt "
    select opt in "${options[@]}" "Back"; do
        if (( REPLY == 1 + ${#options[@]} )); then
            break
        elif (( REPLY > 0 && REPLY <= ${#options[@]} )); then
            selected_file="${options[$REPLY-1]}"
            echo "You picked $selected_file which is file $REPLY"
            unpackingchunks
            echo "File is saved at: $OUTPUTC"       
            exit     
        else
            echo "Invalid option. Try another one."
        fi
    done
}

# FUNCTION START REPACK
function repackpaks {
    prompt="𝗦𝗘𝗟𝗘𝗖𝗧 𝗢𝗣𝗧𝗜𝗢𝗡 :"
    options=($(find /sdcard/Download/TS -name "*.pak" 2>/dev/null))
    
    if [ ${#options[@]} -eq 0 ]; then
        echo -e "${LRED}No .pak files found in UNPACK directory.${NC}"
        return
    fi

    PS3="$prompt "
    select opt in "${options[@]}" "Back"; do
        if (( REPLY == 1 + ${#options[@]} )); then
            break
        elif (( REPLY > 0 && REPLY <= ${#options[@]} )); then
            selected_file="${options[$REPLY-1]}"
            echo "You picked $selected_file which is file $REPLY"
            repackingpaks
            echo "File is saved at: $UNPACK"      
            exit   
        else
            echo "Invalid option. Try another one."
        fi
    done
}
function kuai {
    prompt="𝗦𝗘𝗟𝗘𝗖𝗧 𝗢𝗣𝗧𝗜𝗢𝗡 :"
    options=($(find /sdcard/Download/TS -name "*.pak" 2>/dev/null))
    
    if [ ${#options[@]} -eq 0 ]; then
        echo -e "${LRED}No .pak files found in UNPACK directory.${NC}"
        return
    fi

    PS3="$prompt "
    select opt in "${options[@]}" "Back"; do
        if (( REPLY == 1 + ${#options[@]} )); then
            break
        elif (( REPLY > 0 && REPLY <= ${#options[@]} )); then
            selected_file="${options[$REPLY-1]}"
            echo "You picked $selected_file which is file $REPLY"
            kuaiing
            echo "File is saved at: $UNPACK"      
            exit   
        else
            echo "Invalid option. Try another one."
        fi
    done
}
# MAIN MENU CHUNK or NON-CHUNKS
function chunk {
    PS3='输入你的选择: '
    options=("$(echo -e "${PURPLE}块解包${NC}\n")" "$(echo -e "${LBLUE}非块解包${NC}\n")" "$(echo -e "${YELLOW}𝗕𝗔𝗖𝗞${NC}\n")")
    select opt in "${options[@]}"; do
        case $opt in
            "$(echo -e "${PURPLE}块解包${NC}\n")")
                unpackchunks
                ;;
            "$(echo -e "${LBLUE}非块解包${NC}\n")")
                unpacknonchunks
                ;;
            "$(echo -e "${YELLOW}𝗕𝗔𝗖𝗞${NC}\n")")
                break
                ;;
            *) echo "invalid option $REPLY";;
        esac
    done
}
function tui {
exit
}
function jiao {
clear
echo "1.解包
先对map类文件进行解码，解码之后才可以进行解包
2.打包
先把改好的值放入解码之后的REPACK文件夹中进行打包，完成打包之后在进行加码就OK了
~看明白之后回车出现选择
"
}
# MAIN MENU TS MODE
function main {
PS3='输入你的选择 : '
options=("解包(PUBG 和平精英 pak文件)最新klp技术" "打包(最新klp技术)" "obb(PUBG类)" "map类(PUBG类)" "块打包(缓慢)" "其他功能" "PUBGmap类解包打包教程" "退出")
select opt in "${options[@]}"
do
 case $opt in
    "解包(PUBG 和平精英 pak文件)最新klp技术")
      chunk
     ;;
    "打包(最新klp技术)")
      repackpaks
    ;;
    "obb(PUBG类)")
     tsobb
    ;;
    "map类(PUBG类)")
     map
     ;;
     "块打包")
     kuai
     ;;
     "其他功能")
     sou
     ;;
     "PUBGmap类解包打包教程")
     jiao
     ;;
     "退出")
     tui
     ;;
     *) echo "invalid option $REPLY";;
  esac
done
}
# MAIN EXECUTION
clear
Coloring
banner
check_directories
xuan