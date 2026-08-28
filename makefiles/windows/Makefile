# ----------------------------------------------------
# 構成設定
# ----------------------------------------------------
PRESET     ?= w64devkit
BUILD_DIR  := build/w64devkit
TARGET_EXE := $(BUILD_DIR)/my_game.exe

# ----------------------------------------------------
# ターゲット定義
# ----------------------------------------------------
.PHONY: all build run clean fclean help

# デフォルトターゲット (make とだけ打った場合)
all: build

# 1. CMakeのConfigureおよびビルドを実行
build:
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		cmake --preset $(PRESET); \
	fi
	cmake --build --preset $(PRESET)

# 2. ビルドして実行ファイルを起動
run: build
	./$(TARGET_EXE)

# 3. CMakeで生成された中間生成物のクリア (cmake --build --target clean)
clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		cmake --build --preset $(PRESET) --target clean; \
	fi

# 4. build ディレクトリごと完全削除して初期化
fclean:
	rm -rf build

# 使い方ヘルプを表示
help:
	@echo "利用可能なターゲット:"
	@echo "  make        - プロジェクトをビルドします (デフォルト)"
	@echo "  make build  - プロジェクトをビルドします"
	@echo "  make run    - ビルドした実行ファイルを実行します"
	@echo "  make clean  - オブジェクトファイルなどの中間生成物を削除します"
	@echo "  make fclean - buildディレクトリを完全削除して初期化します"