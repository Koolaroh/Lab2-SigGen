# Clean old build outputs
rm -rf obj_dir
rm -f sinegen_dual.vcd

# Run Verilator to translate SystemVerilog into C++ code
# --cc        : compile to C++
# --trace     : enable waveform tracing (VCD file)
# --exe       : include specified C++ testbench
# -Wall       : enable all compiler warnings
verilator -Wall --cc --trace sinegen_dual.sv rom2ports.sv counter.sv --exe sinegen_dual_tb.cpp

# Build the generated C++ project using Make
# Verilator automatically creates obj_dir/Vsinegen_dual.mk
make -j -C obj_dir/ -f Vsinegen_dual.mk Vsinegen_dual

# Run the simulation executable
obj_dir/Vsinegen_dual
