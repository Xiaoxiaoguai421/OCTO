%test funvtion 'runstats'
[ave,std]=runstats('r');
nvals=input('Enter number of value in data sets:');
for ii=1:nvals
    string=['Enter value' int2str(ii) ':'];
    x=input(string);
    [ave,std]=runstats(x);
    fprintf('Average=%8.4f;std=%8.4f\n',ave,std);
end