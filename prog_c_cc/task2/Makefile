PHONY: all run clean

# コンパイルで生成される実行ファイルの名前
TARGET = main

# 使用するコンパイラ
CC = gcc

# コンパイル時に使用するオプション
CFLAGS = -Wall -g

# ビルドディレクトリ
BUILD_DIR = build

# .oファイルをビルドディレクトリに生成
OBJS = $(BUILD_DIR)/main.o

# デフォルトターゲット
all: $(BUILD_DIR) $(TARGET)

# ビルドディレクトリが存在しない場合は作成
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 実行ファイルを生成するルール
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJS)

# .cファイルから.oファイルを生成するルール
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 実行するルール
run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

# クリーンアップするルール
clean:
	rm -rf $(BUILD_DIR)
