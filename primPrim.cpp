// Har subset of cities ke liye MST nikal
// Let A denote set of all cities
// Agar subset S hai, toh let M be wt of MST of S, m be MST of A-S, aur fir total cost nikal lena
// We sell off all the edges and buy the edges of these MST's back
// Toh answer is sum of all edges- M - m
// Complexity 2^n * (mlogm - For MST finding)