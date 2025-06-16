select eu.unique_id,emp.name
from Employees emp 
left join EmployeeUNI eu
on emp.id = eu.id