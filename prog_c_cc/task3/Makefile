PHONY: all run clean

# コンパイルで生成される実行ファイルの名前
TARGET = main

# 使用するコンパイラ
CC = gcc

# コンパイル時に使用するオプション
CFLAGS = -Wall -g

# ビルドディレクトリ
BUILD_DIR = build

# ライブラリディレクトリ
LIB_DIR = lib

# libディレクトリ内のすべての .c ファイルを取得
LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)

# libディレクトリ内の .c ファイルに対応する .o ファイルをビルドディレクトリに生成
LIB_OBJS = $(patsubst $(LIB_DIR)/%.c, $(BUILD_DIR)/%.o, $(LIB_SRCS))

# .oファイルをビルドディレクトリに生成
OBJS = $(BUILD_DIR)/main.o $(LIB_OBJS)

# デフォルトターゲット
all: $(BUILD_DIR) $(TARGET)

# ビルドディレクトリが存在しない場合は作成
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 実行ファイルを生成するルール
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJS)

# .cファイルから.oファイルを生成するルール
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# main.cファイルをコンパイルするルール
$(BUILD_DIR)/main.o: main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o

# 実行するルール
run: 
	make all -j20
	./$(BUILD_DIR)/$(TARGET)

# クリーンアップするルール
clean:
	rm -rf $(BUILD_DIR)
