#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    private:

        std::string _ideas[100];

    public:
        Brain(void);
        Brain(const Brain& other);
        Brain &operator=(const Brain &other);
        ~Brain();

    void setIdea(int indes, const std::string & idea);
    void getIdea(int index) const;
};

#endif

