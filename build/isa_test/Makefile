ISA_DIR = $(RISCV)/riscv64-unknown-elf/share/riscv-tests/isa

HEX_FILES = $(filter-out %.dump, $(wildcard $(ISA_DIR)/*))
LOG_FILES = $(addprefix $(PWD)/, $(notdir $(addsuffix .swimmer_log, $(HEX_FILES))))

run: $(LOG_FILES)

$(LOG_FILES):
	@./run_swimmer.sh $(addprefix $(ISA_DIR)/, $(basename $(notdir $@))) $@

clean:
	rm -rf $(LOG_FILES) result.txt
