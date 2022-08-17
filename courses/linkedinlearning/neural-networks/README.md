# Neural Networks

1. What is a Nerual Network?
    - A piece of software
    - A model of the brain
    - Capable of reproducing some behaviors of the brain
    - Capable of learning and classifying (thought to recognize categories)

2. What a Nerual network is not:
    - A series of `if` statements or any other hard coded data
    - It is not all what there is to cover machine learning
    - The NN is not the only type of classifiers

3. Structure of a Nerual Network (what constitutes)
    - Collection of neurons(small computing units) that performs simple
      calculations to collectively solve the problems
    - The neurons may be connected in several different ways
    - One of the very popular type of NN is: multilayer perception

4. Popular applications of ML (a field of CS that trains machines to solve
   problems)
    - Image Recognition (where a machine is thought to make sense of still  
      images or video) ex. face recognition in surviellance systems
    - Speech Recognition (input from thousands of thousands of people is used  
      to teach machine recognize different acccents)
    - Prediction (produces stock market advices, weather forecasting and even  
      at different stages of healthcare like diagnostics and treatments)
    - Recommender Systems (video services like Netflix, YouTube or Amazon Prime)  
      They learn from product feedback, given stars, likes, view & purchase  
      history and form the data of people who behave like we.
    - [Guessing Games][1] (by asking simple questions can tell you who or what  
      you are thinking of). Another one is [Think of something 20 questions][2]

5. Three broad paradigms of ML and some of best known tools
    - Supervised Learning (supply a lots of data along with the results what  
      to expect) The main problems that this AI may solve are:
          - Regression (AI comes up with a continuus function that behaves  
            like the provided data)
              - Linear, logistic, exponential (ex. stock market predictions)
          - Classification (recognizes category that sample belongs to)
              - SVM(support vector machines), N
              - Neural networks
              - Decision trees (ex. Akinator)
    - Unsupervised Learning (Where you simply feed data into AI and it makes  
      sense of it on its own) ex:
          - Clustering (Algorithms to divide data samples into clusters, thus  
            learning from the data. (medical, imaging and recommender systems)
          - Anomaly detection (Systems capable of detecting common samples or  
            outliers - crucial for detectin CreditCard frauds, typos in text or  
            medical conditions)
          - Neural Networks (A whole family of NNs that learn from the data) ex:  
            autoencoders, self organising maps, and deep belief networks.
    - Reinforcement Learning (where the AI is composed of feedback loop with  
      rewards and penalties based on its behavior
          - Video game playing AIs without supervision

6. Logistic Regression
    - Perceptrons classify to A/B
    - K-Nearest Neighbors
    - Support Vector Machines (Capable of finding optimal boundary)
    - Decision Trees (Yes/No questions)
    - Feed-forward Neural Networks (Designed to mimic the brain)

7. Neural Networks (architectures)
    - Hopfield Nerual Networks (fully connected)
        - Individual neurons are not aware of the big picture but have influence
        - This type led to Deep NNS
        - Convolutional NNS (deep dreaming: distoring through layers)
    - Multilayer Perceptron
        - The best known feedforward neural network
        - Consist of neurons organized in layers
        - Data traverses the network from input to output
    - Composition:
        - Input Layer (the input vector)
        - Hidden Layers (interconnected neurons)
        - Output Layers (Output values)

8. Brain Resemblance
    - Made of millions of neurons
    - Each neuron performs a very modest cognitive function
    - The combination of the cognitive functions results in the brain's
      mental ability


[1]: <https://en.akinator.com> "Guessing Gin"
[2]: <http://20q.net> "Think of something 20q"
