from sklearn.cluster import KMeans
import numpy as np

# Sample data (replace this with your dataset)
data = np.array(features)

# Create KMeans instance with the desired number of clusters
kmeans = KMeans(n_clusters=3)

# Fit the KMeans model to the data
kmeans.fit(data)

# Get cluster labels
labels = kmeans.labels_

# Get cluster centroids
centroids = kmeans.cluster_centers_

# Print cluster labels and centroids
print("Cluster Labels:", labels)
print("Cluster Centroids:", centroids)