# Remove old build output (obj_dir folder and waveform file)
rm -rf obj_dir
rm -f sinegen.vcd

# 1. Run Verilator to translate Verilog/SystemVerilog into C++
# --cc        : compile to C++
# --trace     : enable waveform tracing (VCD file)
# --exe       : include specified C++ testbench
# -Wall       : enable all compiler warnings

verilator -Wall --cc --trace sinegen.sv rom.sv counter.sv --exe sinegen_tb.cpp

# 2. Build the C++ project automatically with make
# This uses the makefile Verilator generated inside obj_dir/
# (named Vsinegen.mk) to build the executable.
make -j -C obj_dir/ -f Vsinegen.mk Vsinegen

# 3. Run the simulation executable
obj_dir/Vsinegen