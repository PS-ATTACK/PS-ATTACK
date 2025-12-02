#include <bits/stdc++.h>

using namespace std;


vector<string> split(string str){
    vector<string> result;
    size_t previous = 0, current;
    string subStr;

    current = str.find(' ');
    while(current != string::npos){
        subStr = str.substr(previous,current - previous);        
        result.push_back(subStr);
        previous = current + 1;
        current = str.find(' ',previous);
    }
    subStr = str.substr(previous,current - previous);        
    result.push_back(subStr);
    return result;
}
int main()
{
    string answer;
    vector<string> res;
    vector<string>::iterator it;
    int n;
    cin >> n;
    cin.ignore();
    for(int m = 0; m <= n; m++){
    // while(m--){
        getline(cin,answer);
        res = split(answer);

        for (int i = 0; i <= res.size() - 1; i++) {
            for (int j = res[i].size() - 1; j >= 0 ; j--) {
                // cout << res[i][j];
                printf("%c",res[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
{
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}",
    //pylance
    //vim Setting
    //vim Plugin Korean insert version : 1.17.2
    "vim.statusBarColorControl": true,
    "vim.statusBarColors.normal": ["#8FBCBB", "#434C5E"],
    "vim.statusBarColors.insert": "#BF616A",
    "vim.statusBarColors.visual": "#B48EAD",
    "vim.statusBarColors.visualline": "#B48EAD",
    "vim.statusBarColors.visualblock": "#A3BE8C",
    "vim.statusBarColors.replace": "#D08770",
    "vim.statusBarColors.commandlineinprogress": "#007ACC",
    "vim.statusBarColors.searchinprogressmode": "#007ACC",
    "vim.statusBarColors.easymotionmode": "#007ACC",
    "vim.statusBarColors.easymotioninputmode": "#007ACC",
    "vim.statusBarColors.surroundinputmode": "#007ACC",
    "vim.gdefault": true,
    "vim.sneak": false,
    "vim.hlsearch": true,
    "vim.incsearch": true,
    "vim.overrideCopy": true,
    "vim.autoindent": true,
    "vim.foldfix": true,
    "vim.enableNeovim": true,
    "vim.easymotion": true,
    "vim.useSystemClipboard": true,
    "vim.leader": ",",
    "vim.useCtrlKeys": true,
    "vim.visualModeKeyBindings": [
        {
            "before": [ ">" ],
            "commands": [ "editor.action.indentLines" ]
        },
        {
            "before": [ "<" ],
            "commands": [ "editor.action.outdentLines" ]
        },
    ],
   
    "vim.operatorPendingModeKeyBindings": [
    ],
    "vim.normalModeKeyBindings": [
        {
            "before": ["<leader>", "b","m"],
            "commands": [ "bookmarks.toggle" ]
        },
        {
            "before": ["<leader>", "b","l"],
            "commands": [ "bookmarks.list" ]
        },
        {
            "before": [ ">" ],
            "commands": [ "editor.action.indentLines" ]
        },
        {
            "before": [ "<" ],
            "commands": [ "editor.action.outdentLines" ]
        },
        {
            "before": ["j"],
            "after": ["j","z","z"]
            // "after": ["4"]
        },
        {
            "before": ["k"],
            "after": ["k","z","z"]
            // "after": ["4"]
        },
        {
            "before": ["L"],
            "after": ["$"]
            // "after": ["4"]
        },
        {
            "before": ["H"],
            "after": ["^"]
            // "after": ["0"]
        },
        // {
        //     "before": [ ":" ],
        //     "commands": [ "workbench.action.showCommands", ]
        // }
    ],
    "vim.normalModeKeyBindingsNonRecursive": [
        {
            "before": [ "<leader>", "q" ],
            "commands": [ ":bp" ]
        },
        {
            "before": [ "<leader>", "w" ],
            "commands": [ ":bn" ]
        }
    ],
    // "vim.insertModeKeyBindings": [
    //     {
    //         "before": [ "j", "k" ],
    //         "after": [ "<Esc>" ]
    //     }
    // ],
    // "editor.renderWhitespace": "boundary", // 공백 점 생성
    "editor.fontFamily": "FiraCode NF",
    "editor.fontSize": 14,
    "editor.lineHeight": 35, //복사 format
    "explorer.confirmDelete": false,
    "files.exclude": {
        "**/*.dSYM": true,
        "**/*.out": true,
        "**/.classpath": true,
        "**/.project": true,
        "**/.settings": true,
        "**/.factorypath": true
    },
    "C_Cpp.updateChannel": "Insiders",
    //coderunner setting
    "code-runner.executorMap": {
        
        "javascript": "node",
        "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
        "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt.out && $dir$fileNameWithoutExt.out",
        // "cpp": "cd $dir && g++ -std=c++2a -Wall -g $fileName -o $fileNameWithoutExt.out && $dir$fileNameWithoutExt.out",
        // "${fileDirname}/${fileBasenameNoExtension}.out"
        // "cpp": "cd $dir && g++ -std=c++2a -Wall -g $fileName -o $fileNameWithoutExt.out  && $dir$fileNameWithoutExt.out",
        "cpp": "cd $dir && g++ -std=c++2a -O -O1 -O2 -O3 -W -Wall -g $fileName -o a.out  && $dir/a.out",
        // "cpp": "g++ -W -Wall $fullFileName && ./a.out",
        // "cpp": "cd $dir && clang++ -libc++20 -Wall -g $fileName && $dir$fileNameWithoutExt",
        "objective-c": "cd $dir && gcc -framework Cocoa $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "php": "php",
        "python": "python3 -u",
        "perl": "perl",
        "perl6": "perl6",
        "ruby": "ruby",
        "go": "go run",
        "lua": "lua",
        "groovy": "groovy",
        "powershell": "powershell -ExecutionPolicy ByPass -File",
        "bat": "cmd /c",
        "shellscript": "bash",
        "fsharp": "fsi",
        "csharp": "scriptcs",
        "vbscript": "cscript //Nologo",
        "typescript": "ts-node",
        "coffeescript": "coffee",
        "scala": "scala",
        "swift": "swift",
        "julia": "julia",
        "crystal": "crystal",
        "ocaml": "ocaml",
        "r": "Rscript",
        "applescript": "osascript",
        "clojure": "lein exec",
        "haxe": "haxe --cwd $dirWithoutTrailingSlash --run $fileNameWithoutExt",
        "rust": "cd $dir && rustc $fileName && $dir$fileNameWithoutExt",
        "racket": "racket",
        "scheme": "csi -script",
        "ahk": "autohotkey",
        "autoit": "autoit3",
        "dart": "dart",
        "pascal": "cd $dir && fpc $fileName && $dir$fileNameWithoutExt",
        "d": "cd $dir && dmd $fileName && $dir$fileNameWithoutExt",
        "haskell": "runhaskell",
        "nim": "nim compile --verbosity:0 --hints:off --run",
        "lisp": "sbcl --script",
        "kit": "kitc --run",
        "v": "v run",
        "sass": "sass --style expanded",
        "scss": "scss --style expanded",
        "less": "cd $dir && lessc $fileName $fileNameWithoutExt.css",
        "FortranFreeForm": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "fortran-modern": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "fortran_fixed-form": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "fortran": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
    },
    "editor.wordWrap": "on",
    "liveServer.settings.donotVerifyTags": true,
    "liveServer.settings.donotShowInfoMsg": true,
    "editor.tabSize": 4,
    "workbench.editorAssociations": {
        "*.ipynb": "jupyter.notebook.ipynb"
    },
    "editor.find.cursorMoveOnType": false,
    "emmet.includeLanguages": {
        "javascript": "javascriptreact"
    },
    "[javascript]": {
        "editor.defaultFormatter": "vscode.typescript-language-features"
    },
    "workbench.colorTheme": "Monokai Pro",
    "code-runner.ignoreSelection": true,
    "explorer.confirmDragAndDrop": false,
    "editor.suggestSelection": "first",
    "vsintellicode.modify.editor.suggestSelection": "automaticallyOverrodeDefaultValue",
    "cmake.configureOnOpen": true,
    "editor.tokenColorCustomizations": {
        "comments": "#fcc7daf0"
    },
    "editor.cursorBlinking": "phase",
    // "editor.cursorStyle": "block",
    "workbench.startupEditor": "newUntitledFile",
    "workbench.iconTheme": "material-icon-theme",
    "code-runner.runInTerminal": true,
    "terminal.external.osxExec": "iTerm.app",
    // "terminal.integrated.shell.osx": "/bin/zsh",
    "terminal.explorerKind": "external",
    "translator.type": "naver",
    "translator.naver.clientId": "xfeylqPqyjc01mpr3Oh3",
    "translator.naver.clientSecret": "3y_Rh2a2Sw",
    "workbench.colorCustomizations": {
        "statusBar.background": "#007ACC",
        "statusBar.noFolderBackground": "#007ACC",
        "statusBar.debuggingBackground": "#007ACC",
        "statusBar.foreground": "#434C5E",
        "statusBar.debuggingForeground": "#434C5E"
    },
    "editor.smoothScrolling": true,
    "workbench.list.smoothScrolling": true,
    "editor.lineNumbers": "relative",
    "workbench.sideBar.location": "right",
    "markdown-preview-enhanced.scrollSync": true,
    "breadcrumbs.enabled": false,
    "editor.minimap.enabled": false,
    "files.autoSave": "afterDelay",
    "debug.console.lineHeight": 2,
}