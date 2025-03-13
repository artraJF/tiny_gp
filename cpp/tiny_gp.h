// The tiny gp will solve the problem where a user will give a list of numbers and the answer
// then the tiny gp will find the operators that will solve the problem

#include <vector>

class Tiny_GP {
    private:
        enum operators {
            ADD = 0,
            SUB = 1,
            MUL = 2,
            DIV = 3
        };

        std::vector<float> numbers; 
        float              answer;
        int                population_size; 
        int                generations; 
        float              mutation_rate;
        float              crossover_rate;
        float              elitism_rate;

        // Create a random population
        std::vector<operators>* initialize_random_population(int population_size);

        // Evaluate fitness
        float fitness_function(std::vector<operators> individual);

        // Selection
        std::vector<operators> selection();

        // Crossover
        std::vector<operators> crossover(std::vector<operators> parent1, std::vector<operators> parent2);

        // Mutation
        std::vector<operators> mutation(std::vector<operators> individual);

    public:
        
        // Constructor
        Tiny_GP(
            std::vector<float> numbers, 
            float              answer, 
            int                population_size, 
            int                generations, 
            float              mutation_rate,
            float              crossover_rate,
            float              elitism_rate);

        // Run the tiny gp
        void run();

        // Destructor
        ~Tiny_GP();
};