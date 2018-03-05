# Grezzo_1DayInternship
グレッゾさんの1Dayインターンに参加したときの作品です。
## 発生したビルドエラーとその対処法
* 「ソースファイルを開けません」  
Visual Studio内でインクルードパスの設定を直して解決した。  

* 「未解決の外部シンボルxxが関数mainで参照されました」  
MinimunEngine.hの実装はMinimunEngine.libに記述されている可能性があるが、  
どうやらMinimunEngine.libが正常に読み込まれていないようだった。  
プロジェクト自体がx86(32bit)のみに対応しているので、ビルドをx86に切り替えることで解決した。  

* ビルドツールが見つからないエラー  
ソリューションエクスプローラーでminimunSampleプロジェクトを選択して右クリック  
プロパティで、インストール済みのプラットフォームツールを指定してOKをクリックで解決した。  
## 開発環境
* インターン中はVisual Studio 2017、ノートPCに移してからはVisual Studio 2015 Community。
* グレッゾの社員さん作の描画ライブラリMinimumEngine（公開許可承諾済み）  
OpenGLによって構成されています。