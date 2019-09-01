import copy

cols = 7 #int(input("Num cols:"))
rows = 3 #int(input("Num lines:"))
    
def optimal(line):
    for l in line:
        if l < 0:
            return False
            
    return True
    
    
def min_col_index(line):
    return line.index(min(line))

    
def min_row_index(m, col_pivot):
    new_vals = []
    for i in range(1, rows):
        new_vals.append(m[i][-1]/col_pivot)
    
    return new_vals.index(min(new_vals)) + 1
    
    
def div_pivot_row(m, pivot, row):
    new_row = []
    for el in m[row]:
        new_row.append(el/pivot)
    
    m[row] = new_row
    
    
def zero_pivot_col(m, col, pivot_row):
    for r in range(0, rows):
        # nu fac nimic pe randul pivotului
        if r != pivot_row:
            new_row = []
            
            #elementul de pe randul curent si coloana pivotului
            el = m[r][col]
            
            abs_el = abs(el)
            
            # inmultesc randul pivotului cu multiplul pe care trebuie sa il scad/adun
            add_or_subtract_row = map(lambda x: x*abs_el, m[pivot_row])
            
            if el > 0:
                new_row = list(map(lambda x, y: x - y, m[r], add_or_subtract_row))
            else:
                new_row = list(map(lambda x, y: x + y, m[r], add_or_subtract_row))
            
            m[r] = new_row
   
   
def simplex(m):
    while not optimal(m[0]):
        col = min_col_index(m[0])
        row = min_row_index(m, m[0][col])
        
        pivot = m[row][col]
        #print("pivot:", col, row, pivot)
        div_pivot_row(m, pivot, row)
        zero_pivot_col(m, col, row)
        
 
def zero_cols(m):
    for c in range(0, cols-1):
        if m[0][c] != 0:
            for l in range(0, rows):
                m[l][c] = 0
                

def single_one_row(m):
    for l in range(0, rows):
        count_ones = m[l].count(1)
        if count_ones == 1:
            return l
    
    return -1
                
def find_constraints(m, vars):
    row = single_one_row(m)
    
    while row != -1:
        col = m[row].index(1)
        
        vars[col] = m[row][-1]
        
        for c in range(0, cols-1):
            m[row][c] = 0
            
        row = single_one_row(m)    
            
        
if '__main__' == __name__:
    matrix = []
    
    with open("matrice.txt") as f:
        for j in range(0, rows):
            matrix.append([])
            for i in range(0, cols):
                x = int(f.readline())
                matrix[j].append(x)
            
    simplex(matrix)
        
    print(matrix)
    
    matrix2 = copy.deepcopy(matrix)
    zero_cols(matrix2)
    print(matrix2)
    vars = {}
    find_constraints(matrix2, vars)
    print(matrix2)
    
    for i in range(1, cols - rows+1):
        if matrix[0][i] != 0:
            vars[i] = matrix[0][i]
    
    print(vars)