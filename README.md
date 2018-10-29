
    _______  ______  ______   ._____  ______  
      | |   | |     | |  | \ /  | |  | |  | \ 
      | |   | |     | |__|_//   | |  | |__|_/ 
      |_|   |_|____ |_|   ./   _|_|_ |_|      
                                             
    ----------------------------------------

# 目的
ネットワークプログラミングを学習し、自作Webサーバーを開発sする。

## 軌跡

 - 1-1_make-socket.c (2017/10/25)

### 1 Linuxネットワークプログラミング全般

 - socketの作成
 - エラー内容の取得
    - [Man page of ERRNO](https://linuxjm.osdn.jp/html/LDP_man-pages/man3/errno.3.html)
    - [errnoの値の定義を探す - Qiita](https://qiita.com/h2suzuki/items/0cc924cdd9d5c6d47448)
   
### 2 TCP
 - 2.1 TCPを使う
    - [Man page of MEMSET](https://linuxjm.osdn.jp/html/LDP_man-pages/man3/memset.3.html) 
 - 2.2 TCPを使う(サーバ)
    - [Man page of BYTEORDER](https://linuxjm.osdn.jp/html/LDP_man-pages/man3/byteorder.3.html)
 - 2.3 TCPを使う(サーバ、エラー処理付き)
    - [Man page of LISTEN](https://linuxjm.osdn.jp/html/LDP_man-pages/man2/listen.2.html)
    - [Man page of BIND](https://linuxjm.osdn.jp/html/LDP_man-pages/man2/bind.2.html)
    - [Man page of ACCEPT](https://linuxjm.osdn.jp/html/LDP_man-pages/man2/accept.2.html)
    - [Man page of WRITE](https://linuxjm.osdn.jp/html/LDP_man-pages/man2/write.2.html)
 - 2.4 TCPを使う(acceptした相手の確認)
    - [Man page of INET](https://linuxjm.osdn.jp/html/LDP_man-pages/man3/inet_aton.3.html)

 - 2.5 TCPを使う(サーバ、SO_REUSEADDR)
 - 2.6 HTTPサーバの作成（TCPサーバサンプル）
 - 2.7 TCPを使う(クライアント、inet_addr、gethostbyname) 2017/10/28
 - 2.8 TCPを使う(クライアント、gethostbyname) 2017/10/28
 - 2.9 TCPを使う(クライアント、エラー処理付き)
 -     - __HERE__
 - HTTPクライアントの作成(TCPクライアントサンプル)

UDP
UDPを使う
UDPでブロードキャストを使う
UDPでマルチキャストを使う(マルチキャストを送信する)
UDPでマルチキャストを使う(マルチキャストを受信する)
UDPでマルチキャストを使う(TTLを設定する)

その他
IPアドレスからホスト名への変換（gethostbyaddr）
selectの利用
selectの利用(タイムアウト付き)
selectを横から止める方法
pselectでシグナルを無視する

ノンブロッキング設定

簡単なpingの作成（ICMPの送受信）

ネットワーク情報の取得
ネットワークインターフェース情報一覧を取得する（getifaddrs）
ネットワークインターフェース一覧を取得
インターフェースのIPアドレスを取得
インターフェースのネットマスクを取得
インターフェースのMACアドレスを取得

### ネットワーク情報の設定
 - インターフェースにIPv6アドレスを追加
 - インターフェースからIPv6アドレスを削除
 - インターフェースのIPアドレスを設定する
 - インターフェースのネットマスクを設定する
 - インターフェースをdown状態にする
 - インターフェースをup状態にする
 - インターフェースのMACアドレスを設定する
 - インターフェースのMACアドレスを設定する(2)

### IPv6
 - getaddrinfo（単純な例）
 - getaddrinfo（エラー処理）
 - getaddrinfo（getaddrinfoを使ってsockaddrを作成する）
 - getaddrinfo（一番使いそうな例）