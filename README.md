_This project has been created as part of the 42 curriculum by niijima._

# Project name : Libft

## Description

### プロジェクトの目的

独自のライブラリを作成する、関数のコレクションを作る

## Instructions

【Makefileのコマンド】

- make : .oファイルと.aファイルを作成する、一番上のターゲットを作成する（今回の場合はall）

- make all :　.oファイルと.aファイルを作成する

- make clean :　.oファイルを消す

- make fclean :　cleanを実行した上で .aファイルを消す

- make re :　fclean実行した後、allを実行するコマンド

【Makefileの詳細な説明】

- $(NAME): $(OBJS) : オブジェクトファイルを一つにまとめて静的ライブラリを作成する、左はターゲットファイル、右は必要なファイル

- ar : 複数のオブジェクトファイルを一つのアーカイブにまとめるコマンド

- -r : アーカイブにファイルを追加、もし既存であれば更新する（既に静的ライブラリが存在するならば、.oファイルだけを最新のものにする）

- -c : アーカイブが存在しない時に新しく作成する、ライブラリの作成時に生成される通常メッセージを表示しない

- -s :　アーカイブにインデックス（索引）をつける（このライブラリを使うプログラムが目的の関数がどこにあるかを高速にみつけられるようになる）

- %.o: %.c : すべての.oファイルはそれに対応する名前の.cファイルが存在したら、以下のコマンドを実行する

- $< : 入力ファイルの先頭を指す（例：ft_atoi.c）

- $@ : ルールによって作れるべきファイルを指す（例：ft_atoi.o）


## Resources

### 【Part1】

- 変換指定子の確認

https://www.sejuku.net/blog/24934#index_id1

white space asciiの確認

https://www.ascii-code.com/characters/white-space-characters

- 標準ライブラリ関数の理解

https://cgengo.sakura.ne.jp/index.html

https://www.wdic.org/w/TECH/strlcpy

https://www.koeki-prj.org/roy/~yuuji/2021/pe/11/strop.html

https://mogachan.net/clangcmp/

- void型とvoid*型の理解

https://daeudaeu.com/c_void/

const char*sとchar* const sの違いの理解

https://www.ei.fukui-nct.ac.jp/2019/11/13/constcharp-vs-charpconst/

### 【Part2】

- 関数ポインタの理解

https://qiita.com/lightfel/items/04d293ccf2b2184ddc26

- コールバック関数の理解

https://qiita.com/nakajima417/items/4d0c2d46ff82351549e6

- ファイルディスクリプタの理解

https://wa3.i-3-i.info/word14383.html

https://qiita.com/toshihirock/items/78286fccf07dbe6df38f

### 【Part3】

- リスト構造の理解

https://daeudaeu.com/list-structure/

https://daeudaeu.com/arrow/

構造体の理解

https://9cguide.appspot.com/16-01.html

- デリファレンスの意味

https://wa3.i-3-i.info/word12818.html

### 【Others】

- Makefileの書き方

https://qiita.com/yagiyuki/items/ff343d381d9477e89f3b

https://qiita.com/mizcii/items/cfbd2aa17f6b7517c37f

READMEファイルの書き方

https://qiita.com/Qiita/items/c686397e4a0f4f11683d

https://qiita.com/mzmz__02/items/b219c1592404eabda52d


###　【About the use of AI】

使用AI　:　Gemini

用途　:　課題文の理解、自作関数が正しい動作をしているかの確認、エラー文の解説

AIを使う時のプロンプト（Gemini作成）：

役割

あなたはC言語の教育に精通した、厳しくも愛のある「専属コードレビュアー」です。

私の自作関数作成をサポートしてください。

目的

私がC言語の文法やメモリ管理（特にポインタや連結リストなど）を深く理解し、自力でバグのないコードを書けるようになること。

守るべきルール（徹底してください）

1. 正解コードは絶対に書かない：
    - 提出用関数だけでなく、テスト用のメイン関数も含め、完全なコードは提示しないでください。
2. ヒントを段階的に提示する：
    - 私が自分で考えられるよう、概念的な説明やロジックのヒントを優先してください。
3. ミスには厳しく、理由は詳しく：
    - 特にクラッシュ（セグメンテーションフォールト等）に繋がるコードには厳しく指摘してください。
    - 間違いに対しては「なぜそれがダメなのか」の理由を添えてください。
4. 訂正方法は2回目以降：
    - 最初の指摘では「理由とヒント」のみ。私が修正できず、2回目以降に質問した場合のみ、具体的な書き方の改善案（ただし正解そのものではないもの）を提示してください。
5. 高校生にもわかる説明：
    - 難しい概念は例え話などを使い、参考にすべきWebサイトのURL（苦しんで覚えるC言語など）を添えてください。

動作例

私がコードを提示したら、以下の形式で回答してください。

- [問題点の指摘]：どこが、なぜ悪いのか（特にメモリ関連は厳格に）
- [数値例を用いたヒント]：データの動きをシミュレーションする例
- [参考URL]：学習に役立つ外部サイト

これより、作成中のコードを提示します。上記ルールに従ってレビューを開始してください。



## Detailed Description of the Library

### 【Part1】
1\. **ft_isalpha.c**

int isalpha(int c);

文字cが英字であるかを判定する関数

返り値：文字cがテスト対象のクラスに属する場合は1を、属さない場合はゼロを返す

2\. **ft_isdigit.c**

int isdigit(int c);

文字cが数字であるかを判定する関数

返り値：文字cがテスト対象のクラスに属する場合は1を、属さない場合はゼロを返す

3\. **ft_isalnum.c**

int isalnum(int c);

文字cが英数字であるかを判定する関数

返り値：文字cがテスト対象のクラスに属する場合は1を、属さない場合はゼロを返す

4\. **ft_isascii.c**

int isascii(int c);

文字cがASCII文字に含まれる7ビットの符号なし文字型であるかを判定する関数

返り値：文字cがテスト対象のクラスに属する場合は1を、属さない場合はゼロを返す

5\. **ft_isprint.c**

int isprint(int c);

文字cがスペースを含む表示可能文字であるかを判定する関数

返り値：文字cがテスト対象のクラスに属する場合は1を、属さない場合はゼロを返す

6\. **ft_strlen.c**

size_t strlen(const char *s);

文字列の長さをバイト数で取得する関数

返り値：文字列sのバイト数を返す

7\. **ft_memset.c**

void *memset(void *s, int c, size_t n);

メモリ領域sの先頭からnバイトを文字cで埋める関数

返り値：メモリ領域sへのポインタを返す

8\. **ft_bzero.c**

void bzero(void *s, size_t n);

メモリ領域sの先頭からnバイトを0で埋める関数（メモリ内のデータを削除する）

返り値：なし

9\. **ft_memcpy.c**

void *memcpy(void *dest, const void *src, size_t n);

メモリ領域srcに確保されている先頭からnバイトの文字列をメモリ領域destにコピーする関数、文字列終端が含まれていれても、nバイト分コピーする,メモリ領域は重複していてはいけない

返り値：destへのポインタを返す、メモリ領域が重複する場合もdestへのポインタを返す

10\. **ft_memmove.c**

void *memmove(void *dest, const void *src, size_t n);

メモリ領域srcの先頭からnバイトをメモリ領域destに上書きする関数（memcpy()と機能は同じであるが、memmove()はコピー元のメモリ領域とコピー先のメモリ領域が重なっても問題ない）

返り値：destへのポインタを返す

11\. **ft_strlcpy.c**

size_t strlcpy(char *dst, const char *src, size_t size);

メモリ領域srcに確保されている先頭からsizeバイトの文字列をメモリ領域dstにコピーする関数（文字列終端も含む）
途中に文字列終端が含まれている場合はコピーを終える

返り値：srcの長さを返す

12\. **ft_strlcat.c**

size_t strlcat(char *dst, const char *src, size_t size);

文字列srcを文字列dstの末尾にsizeバイト分追加する関数（文字列終端も含む）、追加されるバイト数はsize-strlen(dst)-1

返り値：dstの初期値にsrcの長さを加えたもの、null文字を見つけずにsrcを走査した場合はsizeを返す

13\. **ft_toupper.c**

int toupper(int c);

小文字を大文字に変換する関数

返り値：対応する大文字を返す、存在しない場合はcを返す

14\. **ft_tolower.c**

int tolower(int c);

大文字を小文字に変換する関数

返り値：対応する小文字を返す、存在しない場合はcを返す

15\. **ft_strchr.c**

char *strchr(const char *s, int c);

文字列sから文字cがあるかどうかを探索し、見つかった場合は最初に現れた文字cのポインタを返す関数

返り値：一致する文字へのポインタを返すか、文字が見つからない場合はNULLを返す、終端のヌルバイトは文字列の一部とみなすため、cに'\0'を指定した場合、終端文字へのポインタを返す

16\. **ft_strrchr.c**

char *strrchr(const char *s, int c);

文字列sから文字cがあるかどうかを探索し、見つかった場合は最後に現れた文字cのポインタを返す関数

返り値：一致する文字へのポインタを返すか、文字が見つからない場合はNULLを返す、終端のヌルバイトは文字列の一部とみなすため、cに'\0'を指定した場合、終端文字へのポインタを返す

17\. **ft_strncmp.c**

int strncmp(const char *s1, const char *s2, size_t n);

2つの文字列s1、s2の先頭からnバイトまでを比較する関数

返り値：s1がs2より小さい、一致する、または大きい場合、それぞれ0より小さい、等しい、または0より大きい整数を返す

18\. **ft_memchr.c**

void *memchr(const void *s, int c, size_t n);

文字列sが指すメモリ領域の最初のnバイトをスキャンしてcの最初の出現場所を探す関数

返り値：memchrは一致するバイトへのポインタを返す、指定されたメモリ領域に文字が見つからない場合はNULLを返す

19\. **ft_memcmp.c**

int memcmp(const void *s1, const void *s2, size_t n);

s1で指定されたポインタから始まるnバイトとs2で指定されたポインタから始まるnバイトを比較する関数

返り値：s1の最初のnバイトがs2の最初のnバイトよりも小さい場合、一致する場合、または大きい場合、それぞれ0より小さい、0に等しい、または0より大きい整数を返す
比較して異なる場合はs1とs2で異なる最初の2バイト（unsigned char型）の差の符号によって決まる、nが0の場合は返り値は0

20\. **ft_strnstr.c**

char * strnstr(const char *big, const char *little, size_t len);

文字列bigの中で文字列littleの最初の出現位置を特定する関数、終端文字の後に続く文字は検索されない

返り値：littleが空文字列の場合はbigが返される、littleがbig内に出現しない場合はNULLを返す、それ以外はlittleが最初に出現する箇所の最初の文字へのポインタを返す

21\. **ft_atoi.c**

int atoi(const char *nptr);

文字列の先頭部分の数値部分をint型に変換する関数、整数として認識できない文字列を与えた場合、またはint型の範囲に収まらない文字列を与えた場合の動作は未定義

返り値：変換された値、エラーの場合は0

22\. **ft_calloc.c**

void *calloc(size_t nmemb, size_t size);

各要素が0に初期化されたsizeバイトのnmemb個の要素からなるメモリを新しく確保する関数

返り値：割り当てられたメモリのポインタ、nmembまたはsizeが0の場合、NULLまたは一意のポインタ値を返す（このポインタ値は後でfree関数に渡すことが可能）nmembとsizeの乗算で整数オーバーフローが発生する場合はエラーを返す

23\. **ft_strdup.c**

char *strdup(const char *s);

文字列sの複製である新しい文字列へのポインタを返す関数

返り値：成功した場合は複製された文字列へのポインタを返す、メモリが不足していた場合はNULLを返す

### 【Part2】
1\. **ft_substr.c**

文字列sからインデックスstartから始まり、最大lenまでの部分文字列を取り出し、メモリを確保した新しい配列に格納する関数

2\. **ft_strjoin.c**

文字列s1と文字列s2を連結した文字列をメモリを確保した新しい配列に格納する関数

3\. **ft_strtrim.c**

文字列s1のコピーで先頭と末尾からsetに含まれる文字が消された文字列をメモリを確保した新しい配列に格納する関数

4\. **ft_split.c**

文字cを区切り文字として文字列sを分割して得られた文字列の配列をメモリを確保した新しい配列に格納する関数

5\. **ft_itoa.c**

引数として受け取った整数（負の数を含む）を表す文字列をメモリを確保した新しい文字列に格納する関数

6\. **ft_strmapi.c**

文字列sの各文字に対し関数fを適用し、その結果をメモリを確保した新しい文字列を格納する関数

7\. **ft_striteri.c**

引数として渡された文字列の各文字に対して関数fを適用する関数

8\. **ft_putchar_fd.c**

指定されたファイルに文字cを出力する関数

9\. **ft_putstr_fd.c**

文字列sを指定されたファイルに出力する関数

10\. **ft_putendl_fd.c**

文字列sを指定されたファイルに出力し、その後に改行を追加する関数

11\. **ft_putnbr_fd.c**

指定されたファイルに数字を出力する関数

### 【Part3】
1\. **ft_lstnew.c**

メモリを割当、新しいノードを返す関数。新しいノードのメンバ変数contentは指定されたパラメータcontentで初期化され、変数nextはNULLに初期化される

2\. **ft_lstadd_front.c**

リストの先頭にノードnewを追加する関数

3\. **ft_lstsize.c**

リスト内のノード数をカウントする関数

4\. **ft_lstlast.c**

リストの最後のノードを返す関数

5\. **ft_lstadd_back.c**

リストの末尾にノードnewを追加する関数

6\. **ft_lstdelone.c**

ノードをパラメータとして受け取り、その内容を関数delを使用して解放する関数、ノード自体は解放するが、次のノードは解放しない

7\. **ft_lstclear.c**

指定されたノードとそのリストのすべての要素を関数del、freeを使用して削除し、そのリストへのポインタをNULLに設定する関数

8\. **ft_lstiter.c**

リストlstを反復処理し、関数fを各ノードの内容に適用する関数

9\. **ft_lstmap.c**

リストlstを反復処理し、関数fを各ノードの内容に適用し、関数fを順序に適用した結果を得られる新しいリストを作る関数

### 【Others】

1\. **libft.h**

複数のソースファイルで使用するために関数や変数が宣言されているファイル

2\. **Makefile**

プログラムのビルド作業を自動化するための設定ファイル

3\. **README.md**

プロジェクトの内容、実行方法、関連情報の入手先を素早く理解できるようにするためのファイル
