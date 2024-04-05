//Strategy Pattern
#include <iostream>
#include <vector>

// Strategy interface
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) const = 0;
};

// Concrete strategy 1: Bubble sort
class BubbleSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        // Implementation of bubble sort algorithm
        std::cout << "Sorting using Bubble Sort\n";
        // Actual sorting logic here
    }
};

// Concrete strategy 2: Quick sort
class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        // Implementation of quick sort algorithm
        std::cout << "Sorting using Quick Sort\n";
        // Actual sorting logic here
    }
};

// Context class
class Sorter {
private:
    SortStrategy* strategy;

public:
    Sorter(SortStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy* strategy) {
        this->strategy = strategy;
    }

    void performSort(std::vector<int>& data) {
        strategy->sort(data);
    }
};

int runStrategyPattern() {
    std::vector<int> data = {5, 2, 7, 1, 9};

    Sorter sorter(new BubbleSort()); // Set default strategy to Bubble Sort
    sorter.performSort(data);

    sorter.setStrategy(new QuickSort()); // Change strategy to Quick Sort
    sorter.performSort(data);

    return 0;
}

#include <string>

// Product interface
class Pizza {
public:
    virtual void prepare() const = 0;
    virtual void bake() const = 0;
    virtual void cut() const = 0;
    virtual void box() const = 0;
};

// Concrete product 1: Margherita Pizza
class MargheritaPizza : public Pizza {
public:
    void prepare() const override {
        std::cout << "Preparing Margherita Pizza\n";
    }

    void bake() const override {
        std::cout << "Baking Margherita Pizza\n";
    }

    void cut() const override {
        std::cout << "Cutting Margherita Pizza\n";
    }

    void box() const override {
        std::cout << "Boxing Margherita Pizza\n";
    }
};

// Concrete product 2: Pepperoni Pizza
class PepperoniPizza : public Pizza {
public:
    void prepare() const override {
        std::cout << "Preparing Pepperoni Pizza\n";
    }

    void bake() const override {
        std::cout << "Baking Pepperoni Pizza\n";
    }

    void cut() const override {
        std::cout << "Cutting Pepperoni Pizza\n";
    }

    void box() const override {
        std::cout << "Boxing Pepperoni Pizza\n";
    }
};

// Simple Factory
class PizzaFactory {
public:
    static Pizza* createPizza(const std::string& type) {
        if (type == "Margherita") {
            return new MargheritaPizza();
        } else if (type == "Pepperoni") {
            return new PepperoniPizza();
        }
        return nullptr;
    }
};

int runSimpleFactoryPattern() {
    Pizza* pizza1 = PizzaFactory::createPizza("Margherita");
    pizza1->prepare();
    pizza1->bake();
    pizza1->cut();
    pizza1->box();

    Pizza* pizza2 = PizzaFactory::createPizza("Pepperoni");
    pizza2->prepare();
    pizza2->bake();
    pizza2->cut();
    pizza2->box();

    delete pizza1;
    delete pizza2;

    return 0;
}

int main(){
    runStrategyPattern();
    runSimpleFactoryPattern();

    /*
    In the Strategy pattern example, we have multiple sorting algorithms (Bubble Sort and Quick Sort) that can be interchanged dynamically at runtime, depending on the client's needs.

In the Simple Factory pattern example, we have a factory class (PizzaFactory) responsible for creating different types of pizzas (Margherita and Pepperoni) based on the input parameter ("Margherita" or "Pepperoni"). The client interacts with the factory to obtain instances of different pizza types, but the client doesn't need to know how the pizzas are created internally.







    */


    return 0;
}