/*
 * Harrison, Kevin
 * Vanderhoef, Trevor
 * Vansteel, Alexander
 */

#ifndef GVSU_CS263_SINGLE_LINKED_LIST
#define GVSU_CS263_SINGLE_LINKED_LIST

#include <iostream>
using namespace std;

/* The following single_linked_list class shall be implemented WITHOUT
 * using any of the C++ data structures (std::vector, std::list, std::map,
 * ...)
 *
 * This assignment is primarily a reinforcement of writing recursive
 * functions to manipulate a recursive data structure.
 */

template <typename E>
class single_linked_list {
private:
    /* a struct is a class whose members are all public */
    struct Node;

    Node *head;
public:
    /* the following public functions are NOT RECURSIVE, but they will
     * invoke the recursive counterpart */

    /* Complete each of the following public function */

    /* constructor */
    single_linked_list() {
        head = nullptr;
    }

    /* destructor */
    ~single_linked_list() {
        /* call a RECURSIVE private function for removing
         * all the nodes
         */
        _destructor(head);
    }

    unsigned long size() const {
        return _size(head);
    }

    void print (ostream& destination) const {
        _print(head, destination);
    }

    bool is_contained (const E& x) const {
        return _is_contained (head, x);
    }

    void addItem (const E& x) {
        _add_Item(head, x);
    }

    void remove (const E& x) {
        _removeItem(head, x);
    }

    void print_reverse (ostream& destination) const {
        _print_reverse(head, destination);
    }

private:
    /* the following private functions are RECURSIVE */
    unsigned long _size (Node *from) const {
        if (from != nullptr) {
            int size_after_me = _size(from->next);
            return 1 + size_after_me;
        }
        else
            return 0;
    }

    void _print (Node* from, ostream& out) const {
        if (from != nullptr) {
            out << from->data << " ";
            _print (from->next, out);
        }
    }

    bool _is_contained (Node *from, const E& val) const {
        if (from != nullptr) {
            if (from->data == val) {
                return true;
            }
            else{
                return _is_contained(from->next, val);
            }
        }
        return false;
    }

    void _add_Item(Node* & from, const E& val) const {
        if(from != nullptr) {
            _add_Item(from->next, val);

        }
        else {
            Node *temp = new Node;
            temp->next = nullptr;
            temp->data = val;
            from = temp;
        }
    }

    void _removeItem (Node* & from, const E& val) const {
        if (from != nullptr) {
            if (from->data == val) {
                Node *temp = from;
                from = from->next;
                delete(temp);
            }
            else {
                _removeItem(from->next, val);
            }
        }
    }


    void _destructor (Node* & from) const {
       if (from != nullptr) {
           Node *temp = from;
           from = from->next;
           delete(temp);
           _destructor(from);
       }

    }
    /* The following private functions are Non-Recursive */
    void _print_reverse (Node *from, ostream& out) const {
        int i = (int) size();
        while (i > 0) {
            Node *temp = from;
            for (int n = 1; n < i; n++) {
                temp = temp->next;
            }
            out << temp->data << " ";
            i--;
        }
    }
};

#include "gvsu_node.hpp"

#endif