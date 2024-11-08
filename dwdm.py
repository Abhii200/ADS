# Load ggplot2
library(ggplot2)

# Generate data
set.seed(123)
data <- data.frame(
  x = c(rnorm(50, mean = 5), rnorm(50, mean = 10)),
  y = c(rnorm(50, mean = 5), rnorm(50, mean = 10))
)

# K-means clustering
kmeans_result <- kmeans(data, centers = 2)
data$cluster <- as.factor(kmeans_result$cluster)

# Plot clusters
ggplot(data, aes(x = x, y = y, color = cluster)) +
  geom_point(size = 3) +
  labs(title = "K-means Clustering with 2 Clusters") +
  theme_minimal()

# Print results
print(kmeans_result$centers)
cat("Total within-cluster sum of squares:", kmeans_result$tot.withinss, "\n")


# Sample data with month names
months_data <- c("March", "January", "December", "July", "October")

# Create an ordered factor for months
ordered_months <- factor(months_data, 
                         levels = c("January", "February", "March", "April", "May", "June", 
                                    "July", "August", "September", "October", "November", "December"), 
                         ordered = TRUE)

# Print the ordered factor
print(ordered_months)

# Verify the order
print(sort(ordered_months))

# Load necessary libraries
library(rpart)
library(mlbench)
library(rpart.plot)

# Load the 'readingSkills' dataset
data("readingSkills", package = "mlbench")

# Inspect the dataset
head(readingSkills)

# Build the decision tree model
# Here, 'nativeSpeaker' is the target variable, and the rest are predictors
tree_model <- rpart(nativeSpeaker ~ age + shoeSize + score, data = readingSkills, method = "class")

# Plot the decision tree
rpart.plot(tree_model, main = "Decision Tree for Reading Skills Dataset", type = 3, extra = 102, under = TRUE)

# Print a summary of the model
print(tree_model)


# Initialize counter
counter <- 1

# Use while loop to print numbers from 1 to 10
while (counter <= 10) {
  print(counter)
  counter <- counter + 1
}



# Load necessary libraries
library(party)

# Load the iris dataset
data(iris)

# Build the decision tree model
# 'Species' is the target variable, and the others are predictors
party_tree <- ctree(Species ~ ., data = iris)

# Plot the decision tree
plot(party_tree, main = "Decision Tree using party (ctree)")

# Print a summary of the model
print(party_tree)


# Load necessary libraries
library(rpart)
library(rpart.plot)

# Build the decision tree model
rpart_tree <- rpart(Species ~ ., data = iris, method = "class")

# Plot the decision tree
rpart.plot(rpart_tree, main = "Decision Tree using rpart")

# Print a summary of the model
print(rpart_tree)



# Use for loop to print numbers from 1 to 10
for (i in 1:10) {
  print(i)
}