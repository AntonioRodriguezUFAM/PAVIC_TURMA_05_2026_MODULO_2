// Tutorial 1: Introduction to C++ Multithreading
#include <iostream>
#include <thread>

void print_hello() {
   std::cout << "Hello from thread!" << std::endl;
}

int main() {
   std::thread t(print_hello);
   t.join();
   return 0;
}


// Tutorial 2: Basic Thread Synchronization

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_hello() {
   std::unique_lock<std::mutex> lock(mtx);
   std::cout << "Hello from thread!" << std::endl;
   lock.unlock();
}

int main() {
   std::thread t1(print_hello);
   std::thread t2(print_hello);
   t1.join();
   t2.join();
   return 0;
}


// Tutorial 3: Advanced Thread Synchronization
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_hello() {
   std::unique_lock<std::mutex> lock(mtx);
   cv.wait(lock, [] { return ready; });
   std::cout << "Hello from thread!" << std::endl;
}

int main() {
   std::thread t(print_hello);
   {
       std::unique_lock<std::mutex> lock(mtx);
       ready = true;
   }
   cv.notify_one();
   t.join();
   return 0;
}

// Tutorial 4: Thread-safe Data Structures
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::mutex mtx;
std::queue<int> my_queue;

void push_value(int value) {
   std::unique_lock<std::mutex> lock(mtx);
   my_queue.push(value);
   lock.unlock();
}

int main() {
   std::thread t1(push_value, 1);
   std::thread t2(push_value, 2);
   t1.join();
   t2.join();
   return 0;
}

// Tutorial 5: Thread Pools and Task-based Parallelism
#include <future>
#include <iostream>
#include <vector>

int square(int x) {
   return x * x;
}

int main() {
   std::vector<std::future<int>> futures;

   for (int i = 0; i < 10; ++i) {
       futures.push_back(std::async(std::launch::async, square, i));
   }

   for (auto& f : futures) {
       std::cout << f.get() << std::endl;
   }

   return 0;
}


// CUDA
//Tutorial 6: Introduction to CUDA
#include <iostream>
#include <cuda_runtime.h>

__global__ void hello_cuda() { // GPU
   printf("Hello from CUDA thread %d\n", threadIdx.x);
}

int main() { // CPU
   hello_cuda << <1, 10 >> > ();
   cudaDeviceSynchronize();
   return 0;
}


// Tutorial 7: CUDA Memory Management

#include <iostream>
#include <cuda_runtime.h>

__global__ void add(int* a, int* b, int* c) {
   int idx = threadIdx.x;
   c[idx] = a[idx] + b[idx];
}

int main() {
   int N = 10;
   int size = N * sizeof(int);
   int h_a[N], h_b[N], h_c[N]; // Host
   int** d_a, * dev_b, * dev_c; // Device

   // Initialize host arrays
   for (int i = 0; i < N; ++i) {
       a[i] = i;
       b[i] = i * 2;
   }
    // Allocate Host
malloc

   // Allocate device memory
   cudaMalloc((void**)&dev_a, size);
   cudaMalloc((void**)&dev_b, size);
   cudaMalloc((void**)&dev_c, size);

   // Copy data from host to device
   cudaMemcpy(dev_a, h_a, size, cudaMemcpyHostToDevice);
   cudaMemcpy(dev_b, b, size, cudaMemcpyHostToDevice);

   // Launch kernel
   add << <1, N >> > (dev_a, dev_b, dev_c);

   // Copy data from device to host
   cudaMemcpy(h_c, dev_c, size, cudaMemcpyDeviceToHost);

   // Print results
   for (int i = 0; i < N; ++i) {
       std::cout << a[i] << " + " << b[i] << " = " << c[i] << std::endl;
   }

   // Free device memory
   cudaFree(dev_a);
   cudaFree(dev_b);
   cudaFree(dev_c);

   return 0;
}


//Tutorial 8: Optimizing CUDA Programs

#include <iostream>
#include <cuda_runtime.h>

__global__ void add(int* a, int* b, int* c) {
   int idx = blockIdx.x * blockDim.x + threadIdx.x;
   c[idx] = a[idx] + b[idx];
}

int main() {
   int N = 1024;
   int size = N * sizeof(int);
   int a[N], b[N], c[N];
   int* dev_a, * dev_b, * dev_c;

   // ... (same as previous example)

   // Launch kernel with optimized block and grid dimensions
   int threadsPerBlock = 256;
   int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
   add << <blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, dev_c);

   // ... (same as previous example)
}


// Tutorial 9: CUDA Libraries and Interoperability with C++

#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

int main() {
   thrust::host_vector<int> h_vec(4);
   h_vec[0] = 3;
   h_vec[1] = 1;
   h_vec[2] = 4;
   h_vec[3] = 1;

   thrust::device_vector<int> d_vec = h_vec;

   thrust::sort(d_vec.begin(), d_vec.end());

   h_vec = d_vec;

   for (int i = 0; i < h_vec.size(); ++i) {
       std::cout << h_vec[i] << std::endl;
   }

   return 0;
}


// Tutorial 10: Advanced CUDA Topics
#include <iostream>
#include <cuda_runtime.h>

__global__ void child_kernel() {
   printf("Hello from child kernel %d\n", threadIdx.x);
}

__global__ void parent_kernel() {
   printf("Hello from parent kernel %d\n", blockIdx.x);
   child_kernel << <1, 5 >> > ();
}

int main() {
   parent_kernel << <3, 1 >> > ();
   cudaDeviceSynchronize();
   return 0;
}
