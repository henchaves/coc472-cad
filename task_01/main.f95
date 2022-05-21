program main
implicit none

! 8 bytes each number
real(8), dimension(:, :), allocatable :: A
real(8), dimension(:), allocatable :: x
real(8), dimension(:), allocatable :: b
real(8) :: temp_num

integer :: number_of_rows
integer :: operation
character(100) :: temp_str

integer :: i, j

if(command_argument_count().ne.2)then
  write(*, *) 'Error! Two command-line arguments required.'
  stop
endif

!Read number_of_rows
call get_command_argument(1, temp_str)
read(temp_str, *) number_of_rows

!Read operation
call get_command_argument(2, temp_str)
read(temp_str, *) operation

allocate(A(number_of_rows, number_of_rows)) ! Matrix A
allocate(x(number_of_rows)) ! Vector x
allocate(b(number_of_rows)) ! Vector b


! Fill matrix A and vector x with random numbers
! Fill vector b with zeros
do i=1, number_of_rows
  call random_number(temp_num)
  x(i) = temp_num*10
  b(i) = 0
  do j=1, number_of_rows
    call random_number(temp_num)
    A(i, j) = temp_num*10
  end do
end do

! Multiply matrix (A) by vector (x) and store results to another vector (b)
if (operation == 0) then
  write(*, *) 'Normal Loop'
  do i=1, number_of_rows
    do j=1, number_of_rows
      b(i) = b(i) + A(i, j) * x(j)
    end do
  end do
else
  write(*, *) 'Reversed Loop'
  do j=1, number_of_rows
    do i=1, number_of_rows
      b(i) = b(i) + A(i, j) * x(j)
    end do
  end do
end if

end program