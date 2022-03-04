flags=-std=c++14 -O0 -g

examples=\
build/array \
build/binary_search_tree \
build/binary_tree_complete \
build/binary_tree_traversal \
build/graph \
build/hash \
build/lsh \
build/heap \
build/insertion_sort \
build/list \
build/merge_sort \
build/priority_queue \
build/queue \
build/shortest_paths_bf \
build/shortest_paths_dijkstra \
build/shortest_paths_fw \
build/stack

solutions=\
build/array_delete \
build/array_insert_movable \
build/binary_search_tree_enhanced \
build/binary_tree_enhanced \
build/list_enhanced \
build/list_iterator \
build/queue_enhanced \
build/radix_sort \
build/shortest_paths_fw_decode \
build/shortest_paths_sparse \
build/stack_enhanced \
build/stack_move \
build/stack_rpn

all_examples: $(examples)
all_solutions: $(solutions)

.PHONY: info
info:
	@echo $(examples)
	@echo $(solutions)

build/% : %.cpp
	@mkdir -p build
	c++ ${flags} -MT $@ -MMD -MF build/$*.d $(filter %.cpp, $^) -o $@

build/% : %_driver.cpp
	@mkdir -p build
	c++ ${flags} -MT $@ -MMD -MF build/$*.d $(filter %.cpp, $^) -o $@

.PHONY: distclean
distclean:
	rm -rf build

build/array_delete: array_delete_driver.cpp
build/array_insert_movable: array_insert_movable_driver.cpp
build/array: array_driver.cpp
build/binary_search_tree: binary_search_tree_driver.cpp
build/binary_tree_complete: binary_tree_complete_driver.cpp
build/binary_tree_traversal: binary_tree_traversal_driver.cpp
build/binary_tree_enhanced: binary_tree_enhanced_driver.cpp
build/binary_search_tree_enhanced: binary_search_tree_enhanced_driver.cpp
build/graph: graph_driver.cpp graph.cpp
build/hash: hash_driver.cpp
build/lsh: lsh_driver.cpp
build/heap: heap_driver.cpp
build/insertion_sort: insertion_sort_driver.cpp
build/list_iterator: list_iterator_driver.cpp
build/list_enhanced: list_enhanced_driver.cpp
build/list: list_driver.cpp
build/merge_sort: merge_sort_driver.cpp
build/priority_queue: priority_queue_driver.cpp
build/queue_enhanced: queue_enhanced_driver.cpp
build/queue: queue_driver.cpp
build/radix_sort: radix_sort_driver.cpp
build/shortest_paths_bf: shortest_paths_bf_driver.cpp shortest_paths_bf.cpp graph.cpp
build/shortest_paths_dijkstra: shortest_paths_dijkstra_driver.cpp shortest_paths_dijkstra.cpp graph.cpp
build/shortest_paths_fw_decode: shortest_paths_fw_decode_driver.cpp shortest_paths_fw.cpp graph.cpp
build/shortest_paths_fw: shortest_paths_fw_driver.cpp shortest_paths_fw.cpp graph.cpp
build/shortest_paths_sparse: shortest_paths_sparse_driver.cpp shortest_paths_sparse.cpp  graph.cpp
build/stack_enhanced: stack_enhanced_driver.cpp
build/stack_move: stack_move_driver.cpp
build/stack_rpn: stack_rpn_driver.cpp
build/stack: stack_driver.cpp

pack:
	rm -rf build
	cmake -S . -B build -G Ninja
	cmake --build build --target pack

-include $(addsuffix .d, $(examples) $(solutions))