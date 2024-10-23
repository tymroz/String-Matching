CXX = g++
SRC_DIR = src
BUILD_DIR = build

FA_TARGET = $(BUILD_DIR)/FA.exe
KMP_TARGET = $(BUILD_DIR)/KMP.exe

FA_SRC = $(SRC_DIR)/FA.cpp
KMP_SRC = $(SRC_DIR)/KMP.cpp

all: $(FA_TARGET) $(KMP_TARGET)

$(FA_TARGET): $(FA_SRC)
	$(CXX) $^ -o $@

$(KMP_TARGET): $(KMP_SRC)
	$(CXX) $^ -o $@

run-fa: $(FA_TARGET)
	$(FA_TARGET) ba cases/test1.txt
	@echo.
	$(FA_TARGET) baba cases/test1.txt
	@echo.
	$(FA_TARGET) aba cases/test1.txt
	@echo.
	$(FA_TARGET) ab cases/test2.txt
	@echo.
	$(FA_TARGET) xx cases/test2.txt
	@echo.
	$(FA_TARGET) abc cases/test3.txt
	@echo.
	$(FA_TARGET) abcdefghijk cases/test3.txt
	@echo.

run-kmp: $(KMP_TARGET)
	$(KMP_TARGET) ba cases/test1.txt
	@echo.
	$(KMP_TARGET) baba cases/test1.txt
	@echo.
	$(KMP_TARGET) aba cases/test1.txt
	@echo.
	$(KMP_TARGET) ab cases/test2.txt
	@echo.
	$(KMP_TARGET) xx cases/test2.txt
	@echo.
	$(KMP_TARGET) abc cases/test3.txt
	@echo.
	$(KMP_TARGET) abcdefghijk cases/test3.txt

	

clean:
	rm -f $(BUILD_DIR)/*.exe