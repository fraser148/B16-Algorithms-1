#include "binary_tree_enhanced.hpp"
#include "binary_tree_traversal.hpp"
#include "binary_tree_print.hpp"

int main(int argc, char** argv)
{
  auto bt = make_binary_tree_enhanced(1.0f,
      make_binary_tree_enhanced(2.0f,
        make_binary_tree_enhanced(4.0f, {}, {}),
        make_binary_tree_enhanced(5.0f, {},
          make_binary_tree_enhanced(8.0f, {}, {})
        )
      ),
      make_binary_tree_enhanced(3.0f,
        make_binary_tree_enhanced(6.0f, {}, {}),
        make_binary_tree_enhanced(7.0f, {}, {})
      ));

  std::cout << "Tree:\n";
  print_binary_tree(bt.get());

  auto action = [](const auto& tree) {
      auto parent = tree->parent();
      if (parent) {
          std::cout << "The parent of " << tree->value() << " is "
                    << parent->value() << '\n';
      } else {
          std::cout << "Node " << tree->value() << " has no parent\n";
      }
  };

  df_traversal(bt.get(), action);

  return 0;
}
