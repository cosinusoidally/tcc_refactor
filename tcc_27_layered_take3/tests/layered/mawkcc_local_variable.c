/* This fixture distinguishes true locals from mawkcc's extra-parameter
   convention for simulated local storage. */
function local_identity(value)
{
    var local_value;
    local_value = value;
    return local_value;
}

function main()
{
    return local_identity(7);
}
