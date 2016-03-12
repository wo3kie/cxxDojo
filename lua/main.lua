function hello()
    print "Hello World"
end

function get1()
    return 1
end

function getPi()
    return 3.14
end

function factorial(x)
    if (x == 0 ) then
        return 1
    else
        return x * factorial(x-1)
    end

end

function pow(x, y)
    local result = x

    for i=1, (y-1) do
        result = result * x
    end

    return result
end

