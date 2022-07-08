# makefile for 'court' program

PROGRAM = court
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

LIBS  = `pkg-config opencv4 --cflags --libs`
CXXFLAGS = -Wall -Wunused-result -Wunused-variable -Og

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) ;@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)

$(BIN_DIR)/$(PROGRAM): $(OBJS) ;@mkdir -p $(@D)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)
	@echo Build succeded!

# cleanup
.PHONY: clean

# --- bear --------------------------------------------------------------------
# Generate compile_commands.json file.
.PHONY: bear
bear: clean
	bear make

# --- clean -------------------------------------------------------------------
# Clean up build artifacts.
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
